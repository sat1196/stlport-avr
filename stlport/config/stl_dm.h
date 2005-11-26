// STLport configuration file for Digital Mars C++

#ifndef _STLP_DMC_H
#define _STLP_DMC_H

#if __DMC__ < 0x832
#  error "Digital Mars C++ versions prior to 8.32 are not supported!"
#endif

#ifndef _CPPUNWIND
#  define _STLP_NO_EXCEPTIONS
#endif
#undef _STLP_NO_NAMESPACES
#define _STLP_NO_RELOPS_NAMESPACE
#define _STLP_VENDOR_GLOBAL_CSTD
#define _STLP_VENDOR_GLOBAL_STD
#define _STLP_VENDOR_EXCEPT_STD std

//DMC prefer enum to real static const variable because it do not concider
//static const as const enough to be used in switch declaration...
#define _STLP_STATIC_CONST_INIT_BUG

#define _STLP_DFLT_PARAM_INSTANCIATION_BUG

#if !defined (_WIN32)
// it's not fully supported on non-Win32 platforms
#  define _STLP_NO_NATIVE_WIDE_FUNCTIONS
#endif

#define _STLP_NO_OWN_NAMESPACE
#undef _STLP_NEW_PLATFORM_SDK

// select threads strategy
#if defined (_MT) && !defined (_NOTHREADS)
#  define _REENTRANT
#else
#  define _NOTHREADS
#endif

// unsigned 32-bit integer type
#define _STLP_UINT32_T unsigned

#ifndef _BOOL_DEFINED
#  define _STLP_NO_BOOL
#else
#  define _STLP_DONT_USE_BOOL_TYPEDEF
#endif

#define _STLP_DEFAULT_TYPE_PARAM

#ifndef _WCHAR_T_DEFINED
#  define _STLP_NO_WCHAR_T
#  define _STLP_NO_MBSTATE_T
#endif

#if _INTEGRAL_MAX_BITS >= 64
#  define _STLP_LONG_LONG long long
#endif

#define _STLP_DONT_USE_PRIV_NAMESPACE
#define _STLP_NO_BAD_ALLOC
#define _STLP_NO_MEMBER_TEMPLATE_KEYWORD
//#define _STLP_NONTEMPL_BASE_MATCH_BUG

#define _STLP_HAS_NO_NEW_IOSTREAMS
#define _STLP_HAS_NO_NEW_C_HEADERS
#define _STLP_THROW_RETURN_BUG

#define _STLP_NO_NATIVE_MBSTATE_T

#define _STLP_EXPORT_DECLSPEC __declspec(dllexport)
#define _STLP_IMPORT_DECLSPEC __declspec(dllimport)

#define _STLP_CLASS_EXPORT_DECLSPEC __declspec(dllexport)
#define _STLP_CLASS_IMPORT_DECLSPEC __declspec(dllimport)

#define _STLP_IMPORT_TEMPLATE_KEYWORD __declspec(dllimport)
#define _STLP_EXPORT_TEMPLATE_KEYWORD __declspec(dllexport)

#if defined (__BUILDING_STLPORT)
#  undef _STLP_USE_DYNAMIC_LIB
#  undef _STLP_USE_STATIC_LIB
#  if defined (_WINDLL)
/* We are building the STLport dll */
#    define _STLP_USE_DYNAMIC_LIB
#    if !defined (_DLL)
#      define _STLP_USING_CROSS_NATIVE_RUNTIME_LIB
#    endif
#  else
#    define _STLP_USE_STATIC_LIB
#    if defined (_DLL)
#      define _STLP_USING_CROSS_NATIVE_RUNTIME_LIB
#    endif
#  endif
#else
#  if defined (_DLL)
#    if !defined (_STLP_USE_STATIC_LIB)
#      if !defined (_STLP_USE_DYNAMIC_LIB)
#        define _STLP_USE_DYNAMIC_LIB
#      endif
#    else
/* The user is forcing use of STLport as a dynamic library. We signal it so
 * that the STLport namespace will be modify to report such a combination
 * and force the user to link with the rebuilt STLport library.
 */
#      define _STLP_USING_CROSS_NATIVE_RUNTIME_LIB
#    endif
#  else
#    if !defined(_STLP_USE_DYNAMIC_LIB)
#      if !defined (_STLP_USE_STATIC_LIB)
#        define _STLP_USE_STATIC_LIB
#      endif
#    else
/* Idem previous remark but the user forces use of the static native runtime.
 */
#      define _STLP_USING_CROSS_NATIVE_RUNTIME_LIB
#    endif
#  endif
#endif

#if defined (_STLP_USE_DYNAMIC_LIB)
#  define _STLP_CALL __export

#  undef _STLP_USE_DECLSPEC
#  define _STLP_USE_DECLSPEC 1
#endif

#include <config/_auto_link.h>

#if defined (__BUILDING_STLPORT)
// still needed for building STLport itself, but isn't needed for
// compiling applications anymore
#  undef __SC__
#endif

#endif
