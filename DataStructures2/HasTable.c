#define _CRT_SECURE_NO_WARNINGS

// #include <crtdbg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint64_t hashing_function(const char* key) 
{
	uint64_t hash = 5381;
	for (size_t i = 0; key[i] != 0; ++i) {
		hash = hash * 33 + key[i];
	}
	return hash;
}

typedef struct value_type {
	char nome[50]; // Nome (pu� avere spazi)
	char cognome[50]; // Cognome (pu� avere spazi)
	int anni; // Et� in anni compiuti
	double altezza; // Altezza in metri
} value_type;

typedef struct key_value {
	char *key;
	value_type value;
} key_value;

typedef struct hashmap {
	size_t num_buckets;
	key_value **buckets; // vettore di vettori di key_value
	size_t *buckets_elems; // numero di elementi in ogni bucket
} hashmap;
hashmap *hm_create(hashmap *h, size_t num_buckets) 
{
	h->num_buckets = num_buckets;
	h->buckets = calloc(num_buckets, sizeof(key_value*));
	h->buckets_elems = calloc(num_buckets, sizeof(size_t));
	return h;
}
hashmap *hm_destroy(hashmap *h) 
{
	for (size_t i = 0; i < h->num_buckets; ++i) {
		for (size_t n = 0; n < h->buckets_elems[i]; ++n) {
			free(h->buckets[i][n].key);
		}
		free(h->buckets[i]);
	}
	free(h->buckets);
	free(h->buckets_elems);
	return h;
}
hashmap *new_hashmap(size_t num_buckets) 
{
	return hm_create(malloc(sizeof(hashmap)), num_buckets);
}
void delete_hashmap(hashmap *h) 
{
	free(hm_destroy(h));
}
key_value *hm_find_helper(hashmap *h, const char *key, size_t *nbucket)
{
	uint64_t hash = hashing_function(key);
	size_t n = *nbucket = hash % h->num_buckets;
	for (size_t i = 0; i < h->buckets_elems[n]; ++i) {
		key_value *slot = h->buckets[n] + i;
		if (strcmp(slot->key, key) == 0) {
			return slot;
		}
	}
	return NULL;
}
const value_type *hm_find(hashmap *h, const char *key)
{
	size_t n;
	key_value *slot = hm_find_helper(h, key, &n);
	bool found = slot != NULL;
	if (found) {
		return &(hm_find_helper(h, key, &n)->value);
	}
	return NULL;
}
bool hm_insert(hashmap *h, const char *key, const value_type *value)
{
	size_t n;
	key_value *slot = hm_find_helper(h, key, &n);
	bool found = slot != NULL;
	if (!found) {
		size_t nelems = ++h->buckets_elems[n];
		h->buckets[n] = realloc(h->buckets[n], nelems * sizeof(key_value));
		slot = h->buckets[n] + nelems - 1;
		slot->key = strcpy(malloc(strlen(key) + 1), key);
	}
	memcpy(&slot->value, value, sizeof(*value));
	return !found;
}

int main(void)
{
	hashmap *m = new_hashmap(10);

	bool b;
	b = hm_insert(m, "Mario",    &(value_type){"Mario", "Rossi", 23, 1.80});
	b = hm_insert(m, "Franco",   &(value_type){"Franco", "Verdi", 62, 1.78});
	b = hm_insert(m, "Giovanni", &(value_type){"Giovanni", "Bianchi", 35, 1.69});
	b = hm_insert(m, "Giovanni", &(value_type){"Giovanni", "Neri", 11, 1.41});
	b = hm_insert(m, "Enzo",     &(value_type){"Enzo", "Ferrari", 19, 1.72});

	const value_type *p;
	p = hm_find(m, "Franco");
	p = hm_find(m, "Carlo");
	p = hm_find(m, "Enzo");

	delete_hashmap(m);

	_CrtDumpMemoryLeaks();
	return 0;
}