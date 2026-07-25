#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
  struct stat sb;

  if (argc != 2) {
    printf("Usage: %s <file_path>\n", argv[0]);
    return 1;
  }

  if (stat(argv[1], &sb) == -1) {
    perror("stat");
    return 1;
  }

  char *type;

  switch (sb.st_mode & S_IFMT) {
    case S_IFREG:
      type = "Regular File";
      break;
    case S_IFDIR:
      type = "Directory";
      break;
    case S_IFCHR:
      type = "Character Device";
      break;
    case S_IFBLK:
      type = "Block Device";
      break;
    case S_IFIFO:
      type = "FIFO/Pipe";
      break;
    case S_IFLNK:
      type = "Symbolic Link";
      break;
    case S_IFSOCK:
      type = "Socket";
      break;
    default:
      type = "Unknown";
  }

  printf("=== File Attributes for: %s ===\n", argv[1]);
  printf("File Type:            %s\n", type);
  printf("Permissions:          0%o\n", sb.st_mode & 0777);
  printf("File Size:            %lld bytes\n", (long long)sb.st_size);
  printf("Hard Links Count:     %ld\n", (long)sb.st_nlink);
  printf("Owner (UID):          %d\n", sb.st_uid);
  printf("Group (GID):          %d\n", sb.st_gid);
  printf("Last Access Time:     %s", ctime(&sb.st_atime));
  printf("Last Modification:    %s", ctime(&sb.st_mtime));
  printf("Status Change Time:   %s", ctime(&sb.st_ctime));

  return 0;
}