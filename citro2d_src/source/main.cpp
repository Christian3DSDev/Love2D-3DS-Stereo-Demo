// Written by KonPet

#include <citro2d.h>
#include <3ds.h>

#include "lenny.h"

int main() {
	// Targets for left and right eye respectively
	C3D_RenderTarget* left;
	C3D_RenderTarget* right;
	C2D_SpriteSheet sheet;
	C2D_Image face;
	C2D_SpriteSheet sheett;
	C2D_Image facee;
	int keysD;
	int keysH;
	float slider;

	// Per-eye offsets
	int offsetUpper = 0.3;
	int offsetLower = 0.3;
	int offsetMid = 0.3;

	// Initialize libraries
	romfsInit();
	gfxInitDefault();
	gfxSet3D(true); // Activate stereoscopic 3D
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);

	printf("\x1b[1;1H Stereoscopic 3D with citro2d\n");

	// Create targets for both eyes on the top screen
	left = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	right = C2D_CreateScreenTarget(GFX_TOP, GFX_RIGHT);

	// Load the lenny face
	sheet = C2D_SpriteSheetLoad("romfs:/gfx/lenny.t3x");	
	face = C2D_SpriteSheetGetImage(sheet, 0);
	sheett = C2D_SpriteSheetLoad("romfs:/gfx/lennyr.t3x");	
	facee = C2D_SpriteSheetGetImage(sheett, 0);
	while (aptMainLoop()) {
		// Handle user input
		hidScanInput();
		keysD = hidKeysDown();
		keysH = hidKeysHeld();

		if (keysD & KEY_START) break;

		if (keysD & KEY_DRIGHT || keysH & KEY_DUP) offsetUpper--;
		if (keysD & KEY_DLEFT || keysH & KEY_DDOWN) offsetUpper++;

		if (keysH & KEY_X) offsetLower--;
		if (keysH & KEY_B) offsetLower++;
		
		if (keysH & KEY_A) offsetMid--;
		if (keysH & KEY_Y) offsetMid++;
		slider = osGet3DSliderState();

		// Print useful information
		printf("\x1b[3;1H %.2f | %i | %i          \n", slider, offsetUpper, offsetLower);

		// Render the scene
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);

		// Render the left eye's view
		{
			C2D_TargetClear(left, C2D_Color32(0xff, 0xff, 0xff, 0xff));
			C2D_SceneBegin(left);

			// ScreenWidth - (faceWidth / 2) + offset for 3D
			C2D_DrawImageAt(face, offsetMid * 5, -40 * offsetLower * 0.1, 0,0,0.4 + offsetUpper * 0.01,0.4 + offsetUpper * 0.01);		
			//C2D_DrawImageAt(face, 100 + offsetLower * slider, 140, 0);
		}

		// Render the right eye's view
		{
			C2D_TargetClear(right, C2D_Color32(0xff, 0xff, 0xff, 0xff));
			C2D_SceneBegin(right);

			// ScreenWidth - (faceWidth / 2) - offset for 3D
			C2D_DrawImageAt(facee, offsetMid * 5, -40 * offsetLower * 0.1, 0,0, 0.4 + offsetUpper * 0.01,0.4 +offsetUpper * 0.01);		
			//C2D_DrawImageAt(face, 100 - offsetLower * slider, 140, 0);
		}

		C3D_FrameEnd(0);
	}

	C2D_SpriteSheetFree(sheet);

	// De-initialize libraries
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	romfsExit();
}