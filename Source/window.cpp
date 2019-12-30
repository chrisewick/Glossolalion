#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// project specific includes
#include "model_elements/LanguageModel.h"
#include "ViewObject.h"
#include "PresenterObject.h"
#include "Constants.h"

int main(int argc, char **argv) {
    // seed random
    srand((unsigned int)time(NULL));

	// create the main window
	Fl_Window* window = new Fl_Window(WINDOW_WIDTH, WINDOW_HEIGHT, "Glossolalion Version 0.25");

	LanguageModel* languageModel = new LanguageModel();

	ViewObject* viewObject = nullptr;
	PresenterObject* presenterObject = nullptr;

	// I have no idea why this has to be this way quite yet, but
	// presenter needs to be instantiated before view.
	// If not, view's presenter pointer remains null...?
	presenterObject = new PresenterObject(viewObject, languageModel);
	viewObject = new ViewObject(presenterObject);



	window->end();
	window->show(argc, argv);
	return Fl::run();
}