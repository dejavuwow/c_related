#ifndef OHTBL_H
#define OHTBL_H
typedef struct OHTBL {
	int positions;
	void *vacated;
	int (*h1)(const void *key);
	int (*h2)(const void *key);
	int (*match)(const void *key, const void *key2);
	void (*destroy)(void *data);
	int size;
	void **table;
} OHTBL;

int ohtbl_init(OHTBL *htbl, int positions, int (*h1)(const void *key), int (*h2)(const void *key), int (*match)(const void *key, const void *key2), void (*destroy)(void *data));

void ohtbl_destroy(OHTBL *htbl);
int ohtbl_insert(OHTBL *htbl, const void *data);
int ohtbl_remove(OHTBL *htbl, void *data);
int ohtbl_lookup(const OHTBL *htbl, void *data);
#define ohtbl_size(htbl) ((htbl)->size)
#endif
