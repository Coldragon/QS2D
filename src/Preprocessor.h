﻿#pragma once

//////////////////////////////////
/*
Preproc
*/
//////////////////////////////////

#define QS2D_VERSION "013"

#ifdef QS2D_DEF_STATIC
#define QS2D_DEF static
#elif defined(QS2D_DEF_NO)
#define QS2D_DEF 
#else
#define QS2D_DEF extern
#endif

#ifdef QS2D_USE_DOUBLE
#define QS2D_Float double
#else
#define QS2D_Float float
#endif

#ifdef QS2D_INCLUDE_STBIMAGE
#include QS2D_INCLUDE_STBIMAGE
#endif