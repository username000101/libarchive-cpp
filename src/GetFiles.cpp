#include "libarchive-cpp.hpp"

#include <archive_entry.h>

std::vector<std::pair<libarchive::Archive::EntryType, std::filesystem::path>> libarchive::Archive::get_files() {
    archive* archive = archive_read_new();
    archive_entry* entry;

    this->archive_support_all(archive);
    auto open_result = archive_read_open_filename(archive, this->archive_file_.string().c_str(), 10240);
    if (open_result != ARCHIVE_OK)
        throw std::runtime_error("Failed to open archive: " + std::string(archive_error_string(archive)));

    std::vector<std::pair<EntryType, std::filesystem::path>> result;
    while (archive_read_next_header(archive, &entry) == ARCHIVE_OK) {
        if (archive_entry_mode(entry) == AE_IFDIR)
            result.emplace_back(EntryType::DIRECTORY, std::filesystem::path(archive_entry_pathname(entry)));
        else
            result.emplace_back(EntryType::FILE, std::filesystem::path(archive_entry_pathname(entry)));
        archive_read_data_skip(archive);
    }

    this->archive_close(archive);
    return result;
}