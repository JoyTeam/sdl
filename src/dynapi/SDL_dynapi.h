/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2023 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef SDL_dynapi_h_
#define SDL_dynapi_h_

// Updated by aml.
#define SDL_DYNAMIC_API 0

#ifdef __APPLE__
#include "TargetConditionals.h"
#endif

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE /* probably not useful on iOS. */
#define SDL_DYNAMIC_API 0
#elif defined(__ANDROID__) /* probably not useful on Android. */
#define SDL_DYNAMIC_API 0
#elif defined(__EMSCRIPTEN__) && __EMSCRIPTEN__ /* probably not useful on Emscripten. */
#define SDL_DYNAMIC_API 0
#elif defined(SDL_BUILDING_WINRT) && SDL_BUILDING_WINRT /* probably not useful on WinRT, given current .dll loading restrictions */
#define SDL_DYNAMIC_API 0
#elif defined(__PS2__) && __PS2__
#define SDL_DYNAMIC_API 0
#elif defined(__PSP__) && __PSP__
#define SDL_DYNAMIC_API 0
#elif defined(__riscos__) && __riscos__ /* probably not useful on RISC OS, since dlopen() can't be used when using static linking. */
#define SDL_DYNAMIC_API 0
#elif defined(__clang_analyzer__) || defined(SDL_THREAD_SAFETY_ANALYSIS)
#define SDL_DYNAMIC_API 0 /* Turn off for static analysis, so reports are more clear. */
#elif defined(__VITA__)
#define SDL_DYNAMIC_API 0 /* vitasdk doesn't support dynamic linking */
#elif defined(__NGAGE__)
#define SDL_DYNAMIC_API 0 /* The N-Gage doesn't support dynamic linking either */
#elif defined(__3DS__)
#define SDL_DYNAMIC_API 0 /* devkitARM doesn't support dynamic linking */
#elif defined(DYNAPI_NEEDS_DLOPEN) && !defined(HAVE_DLOPEN)
#define SDL_DYNAMIC_API 0 /* we need dlopen(), but don't have it.... */
#endif

/* everyone else. This is where we turn on the API if nothing forced it off. */
#ifndef SDL_DYNAMIC_API
#define SDL_DYNAMIC_API 1
#endif

#endif
