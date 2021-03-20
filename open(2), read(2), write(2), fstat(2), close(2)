#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <array>
#include <string>

auto cat_to_stdout(std::string const path) -> void
{
        struct stat st;


        auto const in_fd = open(path.c_str(), O_RDONLY);
        if (in_fd == -1) {
                return;
        }

        std::array<char, 4096> buf {0};
        while (true) {
                auto const bytes_in = read(in_fd, buf.data(), buf.size());
                if (bytes_in == -1) {
                        break; //error
                }
                if (bytes_in == 0) {
                        break; //end of file
                }

                write(1, buf.data(), bytes_in);
        }



        if (fstat(in_fd, &st) == -1) {
                close(in_fd);
                return;
        }

        switch (st.st_mode & S_IFMT) {
                case S_IFBLK:  printf("block device\n");      break;
                case S_IFCHR:  printf("character device\n");  break;
                case S_IFDIR:  printf("directory\n");         break;
                case S_IFIFO:  printf("FIFO\n");              break;
                case S_IFLNK:  printf("symlink\n");           break;
                case S_IFREG:  printf("regular file\n");      break;
                case S_IFSOCK: printf("socket\n");            break;
                default:       printf("unknown\n");           break;
        }

        printf("File size:               %lld bytes\n", (long long) st.st_size);
        printf("Last status change:      %s", ctime(&st.st_ctime));
        printf("Last file access:        %s", ctime(&st.st_atime));
        printf("Last file modification:  %s", ctime(&st.st_mtime));

        close(in_fd);
}

auto main (int argc, char* argv[]) -> int
{
        for (auto i = 1; i < argc; ++i) {
                cat_to_stdout(argv[i]);
        }

        return 0;
}
