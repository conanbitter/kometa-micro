#include <stdio.h>
#include <MiniFB.h>
#include <stdlib.h>
#include <stdint.h>

struct mfb_window* window;

void resize(struct mfb_window* window, int width, int height) {
    int scale = width / 320;
    if (scale > height / 240) scale = height / 240;
    if (scale < 1) scale = 1;
    mfb_set_viewport(window, (width - 320 * scale) / 2, (height - 240 * scale) / 2, 320 * scale, 240 * scale);
}

int main() {
    window = mfb_open_ex("Kometa Micro", 320 * 3, 240 * 3, MFB_WF_RESIZABLE);
    if (window == NULL)
        return 0;

    mfb_set_resize_callback(window, &resize);

    uint32_t* buffer = malloc(320 * 240 * 4);
    for (int y = 0;y < 240;y++) {
        for (int x = 0;x < 320;x++) {
            if (x % 240 == y) {
                buffer[x + y * 320] = 0xF0FFC0;
            } else {
                buffer[x + y * 320] = 0x000000;
            }
        }
    }

    mfb_update_state state;
    do {
        // TODO: add some fancy rendering to the buffer of size 800 * 600

        state = mfb_update_ex(window, buffer, 320, 240);

        if (state != MFB_STATE_OK)
            break;

    } while (mfb_wait_sync(window));

    free(buffer);
    buffer = NULL;
    window = NULL;

    return 0;
}