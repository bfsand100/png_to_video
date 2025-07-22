#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_root_name>\n", argv[0]);
        fprintf(stderr, "Example: %s flood\n", argv[0]);
        return 1;
    }

    const char* root = argv[1];

    // Construct input pattern (e.g., flood_%04d.png)
    char input_pattern[256];
    snprintf(input_pattern, sizeof(input_pattern), "%s_%%04d.png", root);

    // Construct output filename (e.g., flood.mp4)
    char output_file[256];
    snprintf(output_file, sizeof(output_file), "%s.mp4", root);

    // Build ffmpeg command
    char cmd[512];
    snprintf(cmd, sizeof(cmd),
             "ffmpeg -framerate 10 -i %s -pix_fmt yuv420p -y %s",
             input_pattern, output_file);

    printf("Running command: %s\n", cmd);
    int result = system(cmd);

    if (result != 0) {
        fprintf(stderr, "Error: ffmpeg command failed.\n");
        return 1;
    }

    printf("Success: %s generated.\n", output_file);
    return 0;
}
