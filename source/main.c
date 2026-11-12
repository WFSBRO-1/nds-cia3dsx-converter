#include <3ds.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

#define OUTPUT_DIR "sdmc:/converterNC3"

static bool ensure_output_directory(void)
{
    struct stat st;

    if (stat(OUTPUT_DIR, &st) == 0)
        return S_ISDIR(st.st_mode);

    if (mkdir(OUTPUT_DIR, 0777) == 0)
        return true;

    if (errno == EEXIST && stat(OUTPUT_DIR, &st) == 0)
        return S_ISDIR(st.st_mode);

    return false;
}

int main(void)
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    printf("\x1b[1;1HNDS CIA/3DSX CONVERTER");
    printf("\x1b[3;1HVersion 0.1 — first prototype");
    printf("\x1b[5;1HChecking SD card folder...");

    bool folder_ok = ensure_output_directory();

    if (folder_ok) {
        printf("\x1b[7;1H[OK] SD:/converterNC3/");
        printf("\x1b[9;1HOutput directory is ready.");
    } else {
        printf("\x1b[7;1H[ERROR] Cannot create/access folder.");
        printf("\x1b[9;1HCheck that the SD card is mounted.");
    }

    printf("\x1b[12;1HNext: NDS file browser + forwarder builder");
    printf("\x1b[15;1HPress START to exit.");

    while (aptMainLoop())
    {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START)
            break;

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}
