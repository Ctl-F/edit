#ifndef __EDIT_H__
#define __EDIT_H__

#include "textbuffer.h"

#include <SDL3/SDL.h>
#include <stdexcept>

namespace ed {

struct WinParams {
	int width;
	int height;
	const char* title;
};

class EditCtx {
public:
	EditCtx(const WinParams* params = nullptr);
	~EditCtx();
private:
	static bool s_IsSDLInit;
	static unsigned s_InstanceCount;
	
	SDL_Window* m_Window = nullptr;
	SDL_Surface* m_Surface = nullptr;

private:
	static const WinParams* default_params() noexcept;
};

}

#endif
