#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <math.h>

//#pragma warning(enable:C4005)

#if defined(WIN32)

#define PLATFORM_WIN32 1

#include <Windows.h>
#include <malloc.h>
#include <GL/GL.h>
#include <GL/GLU.h>
//#include "win_glext/glext.h"
//#include "jansson.h"

//#define myinline __forceinline

#elif defined(ANDROID) || defined(_ANDROID)

#define PLATFORM_ANDROID 1

#include <jni.h>
#include <malloc.h>
#if 1
#include <GLES/gl.h>
#include <GLES/glext.h>
#else
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#endif

#elif defined(__linux)

#define PLATFORM_LINUX 1

#include <linux/stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>
#include <libgen.h>

#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glxext.h>

#include <dlfcn.h>
#include <jansson.h>

#include <pthread.h>

//#define myinline inline

#elif defined(__APPLE__)

//#define myinline __inline__ __attribute__((always_inline))
//#define forceinline __inline__ __attribute__((always_inline))
//#define ensure_forceinline __attribute__((always_inline)) // inline or die

#include "TargetConditionals.h"
#if (TARGET_OS_IPHONE && TARGET_IPHONE_SIMULATOR) || TARGET_OS_IPHONE
// define something for simulator

	#define PLATFORM_IPHONE 1

	#include <OpenGLES/ES2/gl.h>

// define something for iphone
#else
	#define PLATFORM_OSX 1

	#include <OpenGL/gl.h>
	#include <OpenGL/gl3.h>
	#include <OpenGL/glext.h>
#endif

//#include <OpenGLES/ES1/gl.h>
//#include <OpenGLES/ES1/glext.h>

#else

#error "PLATFORM: system not defined"

#endif

#define IS_PLATFORM_WIN32 (defined(PLATFORM_WIN32) && 1 == PLATFORM_WIN32)
#define IS_PLATFORM_ANDROID (defined(PLATFORM_ANDROID) && 1 == PLATFORM_ANDROID)
#define IS_PLATFORM_LINUX (defined(PLATFORM_LINUX) && 1 == PLATFORM_LINUX)
#define IS_PLATFORM_IPHONE (defined(PLATFORM_IPHONE) && 1 == PLATFORM_IPHONE)
#define IS_PLATFORM_OSX (defined(PLATFORM_OSX) && 1 == PLATFORM_OSX)

#endif // PLATFORM_H
