#include "include/edit.h"


namespace ed {   

bool EditCtx::s_IsSDLInit = false;
unsigned EditCtxx::s_InstanceCount = 0;

EditCtx::EditCtx(const WinParams* params) {
	if(!s_IsSDLInit){
		if(SDL_Init(SDL_INIT_VIDEO) < 0){
			throw std::runtime_error("Could not init SDL");
		}
		s_IsSDLInit = true;
	}

	if(params == nullptr){
		params = default_params();
	}

	m_Window = SDL_CreateWindow(params.title, 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		params.width, params.height, 0);

	if(!m_Window){
		SDL_Quit();
		s_IsSDLInit = false;
		throw std::runtime_error("Error creating sdl window");
	}
	
	m_Surface = SDL_GetWindowSurface(m_Window);

	s_InstanceCount++;
}

EditCtx::~EditCtx(){
	if(!m_Window){
		SDL_DestroyWindow(m_Window);
		m_Window = nullptr;
	}
	if(--s_InstanceCount == 0){
		SDL_Quit();
		s_IsSDLInit = false;
	}
}


static const WinParams* EditCtx::default_params() noexcept {
	static WinParams s_Params = {
		.width = 800,
		.height = 600,
		.title = "Edit"
	};

	return &s_Params;
}

}

