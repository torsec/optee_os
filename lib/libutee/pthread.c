#include <tee_internal_api.h>
#include <tee_internal_api_extensions.h>
typedef struct {
    int locked; // 0 = unlocked, 1 = locked
} TEE_Mutex;

void TEE_MutexInit(TEE_Mutex *mutex) {
    __atomic_store_n(&mutex->locked, 0, __ATOMIC_RELAXED); // Inizializza come sbloccato
}

void TEE_MutexLock(TEE_Mutex *mutex) {
    while (__atomic_exchange_n(&mutex->locked, 1, __ATOMIC_ACQUIRE)) {
        // Spinlock: attende che il mutex sia sbloccato
    }
}

void TEE_MutexUnlock(TEE_Mutex *mutex) {
    __atomic_store_n(&mutex->locked, 0, __ATOMIC_RELEASE); // Sblocca il mutex
}

typedef struct {
    int is_initialized;      // Indica se la funzione è già stata eseguita
    TEE_Mutex mutex;         // Mutex per sincronizzazione
} pthread_once_t;


int pthread_once(pthread_once_t *once_control, void (*init_routine)(void)) {
    // Controlla se il puntatore è valido
    if (once_control == NULL || init_routine == NULL) {
        return -1;  // Errore
    }

    // Acquisisci il mutex
    TEE_MutexLock(&once_control->mutex);

    if (once_control->is_initialized == 0) {
        // Esegui la routine di inizializzazione
        init_routine();
        // Aggiorna lo stato
        once_control->is_initialized = 1;
    }

    // Rilascia il mutex
    TEE_MutexUnlock(&once_control->mutex);

    return 0;  // Successo
}