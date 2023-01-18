/**
 * @file core.h
 * @copyright 2003-2023 projectM Team
 * @brief Core functions to instantiate, destroy and control projectM.
 *
 * projectM -- Milkdrop-esque visualisation SDK
 * Copyright (C)2003-2023 projectM Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * See 'LICENSE.txt' included within this release
 *
 */

#pragma once

#include "libprojectM/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates a new projectM instance.
 * @return A projectM handle for the newly created instance that must be used in subsequent API calls.
 *         NULL if the instance could not be created successfully.
 */
PROJECTM_EXPORT projectm_handle projectm_create();

/**
 * @brief Destroys the given instance and frees the resources.
 *
 * After destroying the handle, it must not be used for any other calls to the API.
 *
 * @param instance A handle returned by projectm_create() or projectm_create_settings().
 */
PROJECTM_EXPORT void projectm_destroy(projectm_handle instance);

/**
 * @brief Loads a preset from the given filename/URL.
 *
 * Ideally, the filename should be given as a standard local path. projectM also supports loading
 * "file://" URLs. Additionally, the special filename "idle://" can be used to load the default
 * idle preset, displaying the "M" logo.
 *
 * Other URL schemas aren't supported and will cause a loading error.
 *
 * If the preset can't be loaded, no switch takes place and the current preset will continue to
 * be displayed. Note that if there's a transition in progress when calling this function, the
 * transition will be finished immediately, even if the new preset can't be loaded.
 *
 * @param instance The projectM instance handle.
 * @param filename The preset filename or URL to load.
 * @param smooth_transition If true, the new preset is smoothly blended over.
 */
PROJECTM_EXPORT void projectm_load_preset_file(projectm_handle instance, const char* filename,
                                               bool smooth_transition);

/**
 * @brief Loads a preset from the data pointer.
 *
 * Currently, the preset data is assumed to be in Milkdrop format.
 *
 * If the preset can't be loaded, no switch takes place and the current preset will continue to
 * be displayed. Note that if there's a transition in progress when calling this function, the
 * transition will be finished immediately, even if the new preset can't be loaded.
 *
 * @param instance The projectM instance handle.
 * @param data The preset contents to load.
 * @param smooth_transition If true, the new preset is smoothly blended over.
 */
PROJECTM_EXPORT void projectm_load_preset_data(projectm_handle instance, const char* data,
                                               bool smooth_transition);

/**
 * @brief Reloads all textures.
 *
 * Calling this method will clear and reload all textures, including the main rendering texture.
 * Can cause a small delay/lag in rendering. Only use if texture paths were changed.
 *
 * @param instance The projectM instance handle.
 */
PROJECTM_EXPORT void projectm_reset_textures(projectm_handle instance);

#ifdef __cplusplus
} // extern "C"
#endif
