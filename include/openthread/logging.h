/*
 *  Copyright (c) 2016-2018, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * @brief
 *   This file includes OpenThread logging related definitions.
 */

#ifndef OPENTHREAD_LOGGING_H_
#define OPENTHREAD_LOGGING_H_

#include <openthread/error.h>
#include <openthread/platform/logging.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup api-logging
 *
 * @brief
 *   This module includes OpenThread logging related definitions.
 *
 * @{
 *
 */

/**
 * This function returns the current log level.
 *
 * If dynamic log level feature `OPENTHREAD_CONFIG_ENABLE_DYNAMIC_LOG_LEVEL` is enabled, this function returns the
 * currently set dynamic log level. Otherwise, this function returns the build-time configured log level.
 *
 * @returns The log level.
 *
 */
otLogLevel otLoggingGetLevel(void);

/**
 * This function returns the current log level of the given region.
 * 
 * If dynamic region log level feature 'OPENTHREAD_CONFIG_ENABLE_DYNAMIC_REGION_LOG_LEVEL' is enabled, this
 * returns currently set dynamic region log level. Otherwise, this function will return dynamic log level if
 * the 'OPENTHREAD_CONFIG_ENABLE_DYNAMIC_LOG_LEVEL' is enabled or it will return build-time configured log level
 * if it is disabled.
 */
otLogLevel otLoggingGetRegionLevel(otLogRegion aRegion);

/**
 * This function sets the log level.
 *
 * @note This function requires `OPENTHREAD_CONFIG_ENABLE_DYNAMIC_LOG_LEVEL=1`. If dynamic region log level is 
 * enabled this function will set given level for every region.
 *
 * @param[in]  aLogLevel               The log level.
 *
 */
void otLoggingSetLevel(otLogLevel aLogLevel);

/**
 * This function sets the log level of the given region.
 * 
 * @note This function requires `OPENTHREAD_CONFIG_ENABLE_DYNAMIC_LOG_LEVEL=1` and 
 * `OPENTHREAD_CONFIG_ENABLE_DYNAMIC_REGION_LOG_LEVEL=1`.
 * 
 * @param[in] aLogLevel                The log level.
 * @param[in] aRegion                  The region.
 */
void otLoggingSetRegionLevel(otLogLevel aLogLevel, otLogRegion aRegion);

/**
 * @}
 *
 */

#ifdef __cplusplus
} // extern "C"
#endif

#endif // OPENTHREAD_LOGGING_H_
