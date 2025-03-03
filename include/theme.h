#ifndef __THEME_H__
#define __THEME_H__

#include <SDL3/SDL.h>
#include <cstdint>
#include <array>

namespace ed {

	struct RGBA {
		union {
			uint32_t color;
			struct {
				uint8_t red;
				uint8_t green;
				uint8_t blue;
				uint8_t alpha;
			};
		};

		inline RGBA& operator=(const RGBA& other) noexcept {
			this->color = other.color;
			return *this;
		}
		inline RGBA& operator=(uint32_t color) noexcept {
			this->color = color;
			return *this;
		}
		
		inline operator uint32_t() const noexcept {
			return this->color;
		}
	};

	struct Theme {
		uint32_t bg;
		uint32_t fg_default;
		uint32_t fg_number;
		uint32_t fg_comment;
		uint32_t fg_operator;
		uint32_t fg_contained_string;
		std::array<uint32_t, 16> fg_keyword;
	};

	bool load_theme(const char* filename, Theme& theme) noexcept;
	void default_theme(Theme& theme) noexcept;
}

#endif

