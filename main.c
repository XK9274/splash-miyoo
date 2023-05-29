#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_rotozoom.h"

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Usage: %s <image_file> <red> <green> <blue>\n", argv[0]);
        return 1;
    }

    const char* image_path = argv[1];
    int red = atoi(argv[2]);
    int green = atoi(argv[3]);
    int blue = atoi(argv[4]);

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_image
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return 1;
    }

    SDL_Surface* screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        printf("Could not create screen! SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    // Fill screen with specified background color
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, red, green, blue));

    // Update the screen
    SDL_UpdateRect(screen, 0, 0, 0, 0);

    // Load image
    SDL_Surface* loadedImage = IMG_Load(image_path);
    if (loadedImage == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", image_path, IMG_GetError());
        return 1;
    }

    // Rotate image 180 degrees
    SDL_Surface* rotatedImage = rotozoomSurface(loadedImage, 180, 1, 0);
    if (rotatedImage == NULL) {
        printf("Unable to rotate image! SDL_gfx Error: %s\n", SDL_GetError());
        return 1;
    }

    // Center image on screen
    SDL_Rect dstrect;
    dstrect.x = (screen->w - rotatedImage->w) / 2;
    dstrect.y = (screen->h - rotatedImage->h) / 2;

    // Draw rotated image on screen
    SDL_BlitSurface(rotatedImage, NULL, screen, &dstrect);
    SDL_Flip(screen);

    // Wait 5 seconds then quit
    SDL_Delay(5000);

    // Free surfaces
    SDL_FreeSurface(loadedImage);
    SDL_FreeSurface(rotatedImage);

    // Quit SDL
    SDL_Quit();

    return 0;
}