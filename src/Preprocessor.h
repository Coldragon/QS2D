#pragma once

//////////////////////////////////
/*
Preproc
*/
//////////////////////////////////

#define QS2D_VERSION "005"

#ifdef QS2D_USE_STATIC
#define QS2D_DEF static
#else
#define QS2D_DEF extern
#endif

#ifdef QS2D_USE_DOUBLE
#define QS2D_Float double
#else
#define QS2D_Float float
#endif
