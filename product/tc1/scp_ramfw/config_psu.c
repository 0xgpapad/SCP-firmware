/*
 * Arm SCP/MCP Software
 * Copyright (c) 2021, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <tc1_mock_psu.h>
#include <tc1_psu.h>

#include <mod_mock_psu.h>
#include <mod_psu.h>

#include <fwk_element.h>
#include <fwk_module.h>
#include <fwk_module_idx.h>

static const struct fwk_element element_table[PSU_ELEMENT_IDX_COUNT + 1] = {
    [PSU_ELEMENT_IDX_KLEIN] = {
        .name = "PSU_GROUP_KLEIN",
        .data =
            &(const struct mod_psu_element_cfg){
                .driver_id = FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_MOCK_PSU,
                    MOCK_PSU_ELEMENT_IDX_KLEIN),
                .driver_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_MOCK_PSU,
                    MOD_MOCK_PSU_API_IDX_DRIVER) },
    },
    [PSU_ELEMENT_IDX_MAKALU] = {
        .name = "PSU_GROUP_MAKALU",
        .data =
            &(const struct mod_psu_element_cfg){
                .driver_id = FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_MOCK_PSU,
                    MOCK_PSU_ELEMENT_IDX_MAKALU),
                .driver_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_MOCK_PSU,
                    MOD_MOCK_PSU_API_IDX_DRIVER) },
    },
    [PSU_ELEMENT_IDX_MAKALU_ELP] = {
        .name = "PSU_GROUP_MAKALU_ELP",
        .data =
            &(const struct mod_psu_element_cfg){
                .driver_id = FWK_ID_ELEMENT_INIT(FWK_MODULE_IDX_MOCK_PSU,
                    MOCK_PSU_ELEMENT_IDX_MAKALU_ELP),
                .driver_api_id = FWK_ID_API_INIT(
                    FWK_MODULE_IDX_MOCK_PSU,
                    MOD_MOCK_PSU_API_IDX_DRIVER) },
    },

    { 0 }
};

static const struct fwk_element *psu_get_element_table(fwk_id_t module_id)
{
    return element_table;
}

const struct fwk_module_config config_psu = {
    .elements = FWK_MODULE_DYNAMIC_ELEMENTS(psu_get_element_table),
};
