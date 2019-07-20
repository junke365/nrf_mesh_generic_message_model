/* Copyright (c) 2010 - 2018, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GENERIC_MESSAGE_COMMON_H__
#define GENERIC_MESSAGE_COMMON_H__

#include <stdint.h>
#include "model_common.h"

/**
 * @defgroup GENERIC_MESSAGE_MODEL Generic Message model
 * @ingroup MESH_API_GROUP_GENERIC_MODELS
 * This model implements the message based interface required to set the message value on the server.
 * Server model itself is a stateless model. The state information resides in the user application.
 * This interface API takes care of validating the packet formats and field values.
 * These APIs should be used in combination with necessary behavioral implementation to create
 * a qualifiable model implementation.
 * @{
 */

/** Model Company ID */
#define GENERIC_MESSAGE_COMPANY_ID 0xFFFF

/**
 * Unpacked message structure typedefs are used for API interfaces and for implementing model code. This helps to minimize code
 * footprint.
 */

/** Structure containing value of the message state */
typedef struct
{
    bool message;                                            /**< State to set */
    uint8_t tid;                                            /**< Transaction ID */
} generic_message_state_t;

/** Mandatory parameters for the Generic message Set message. */
typedef struct
{
    bool message;                                            /**< State to set */
    uint8_t tid;                                            /**< Transaction ID */
} generic_message_set_params_t;

/** Parameters for the Generic message Status message. */
typedef struct
{
    uint8_t present_message;                                 /**< The present value of the Generic message state */
    uint8_t target_message;                                  /**< The target value of the Generic message state (optional) */
    uint32_t remaining_time_ms;                             /**< Remaining time value in milliseconds */
} generic_message_status_params_t;

/**@} end of GENERIC_MESSAGE_MODEL */
#endif /* GENERIC_MESSAGE_COMMON_H__ */
