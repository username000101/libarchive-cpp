#include <archive_entry.h>

#include "libarchive-cpp.hpp"

std::filesystem::path libarchive::Archive::extract(std::filesystem::path output_dir) {
    if (!std::filesystem::exists(output_dir))
        std::filesystem::create_directories(output_dir);

    archive* archive = archive_read_new();
    archive_entry* entry;

    this->archive_support_all(archive);

    archive_read_open_filename(archive, this->archive_file_.c_str(), 10240);
    while (archive_read_next_header(archive, &entry) == ARCHIVE_OK) {
        auto tmp_path = (output_dir / archive_entry_pathname(entry)).string();
        archive_entry_set_pathname(entry, tmp_path.c_str());
        auto extract_result = archive_read_extract(archive, entry, ARCHIVE_EXTRACT_TIME);
        if (extract_result != ARCHIVE_OK)
            throw std::runtime_error("Failed to extract file: " + std::string(archive_error_string(archive)));
    }

    this->archive_close(archive);
    return output_dir;
}