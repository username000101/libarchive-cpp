#pragma once

#include <filesystem>

#include <archive.h>

#include <utility>
#include <vector>

namespace libarchive {
    class Archive {
    public:
        Archive(std::filesystem::path file) : archive_file_(file) {}

        enum EntryType { FILE, DIRECTORY };
        std::vector<std::pair<EntryType, std::filesystem::path>> get_files();
        std::filesystem::path extract(std::filesystem::path output_dir);

    private:
        void archive_support_all(archive* archive) {
            if (!archive)
                return;
            archive_read_support_format_all(archive);
            archive_read_support_filter_all(archive);
        }
        void archive_close(archive* archive) {
            if (!archive)
                return;
            archive_read_close(archive);
            archive_read_free(archive);
        }

        std::filesystem::path archive_file_;
    };
}