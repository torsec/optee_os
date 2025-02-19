#include <assert.h>
#include <config.h>
#include <stdlib.h>
#include <string.h>
#include <string_ext.h>
#include <tee_api.h>
#include <tee_api_defines_extensions.h>
#include <tee_internal_api_extensions.h>
#include <utee_syscalls.h>
#include <utee_defines.h>
#include <util.h>
#include "tee_api_private.h"

// Definizione della funzione getentropy
TEE_Result getentropy(void *buffer, size_t length) {
    TEE_Result res;

    if (!buffer || length == 0) {
        return TEE_ERROR_BAD_PARAMETERS; // Controllo dei parametri
    }

    // Generazione di byte casuali
    res = _utee_cryp_random_number_generate(buffer, length);
    if (res != TEE_SUCCESS)
	TEE_Panic(res);
    return TEE_SUCCESS; // Generazione riuscita
}