#pragma once

#include <libavcodec/avcodec.h>

/* LIBAVCODEC_VERSION_CHECK checks for the right version of libav and FFmpeg
 * a is the major version
 * b and c the minor and micro versions of libav
 * d and e the minor and micro versions of FFmpeg */
#define LIBAVCODEC_VERSION_CHECK( a, b, c, d, e ) \
    ( (LIBAVCODEC_VERSION_MICRO <  100 && LIBAVCODEC_VERSION_INT >= AV_VERSION_INT( a, b, c ) ) || \
      (LIBAVCODEC_VERSION_MICRO >= 100 && LIBAVCODEC_VERSION_INT >= AV_VERSION_INT( a, d, e ) ) )

#if !LIBAVCODEC_VERSION_CHECK(54, 28, 0, 59, 100)
# define avcodec_free_frame av_freep
#endif

#if LIBAVCODEC_VERSION_INT < 0x371c01
# define av_frame_alloc avcodec_alloc_frame
# define av_frame_unref avcodec_get_frame_defaults
# define av_frame_free avcodec_free_frame
#endif

