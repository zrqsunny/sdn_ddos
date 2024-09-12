/* Generated automatically -- do not modify!    -*- buffer-read-only: t -*- */

#ifndef SERVERREC_IDL_HEADER
#define SERVERREC_IDL_HEADER 1

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "ovsdb-data.h"
#include "ovsdb-idl-provider.h"
#include "smap.h"
#include "uuid.h"

#ifdef  __cplusplus
extern "C" {
#endif


/* Database table. */
struct serverrec_database {
	struct ovsdb_idl_row header_;

	/* cid column. */
	struct uuid *cid;
	size_t n_cid;

	/* connected column. */
	bool connected;

	/* index column. */
	int64_t *index;
	size_t n_index;

	/* leader column. */
	bool leader;

	/* model column. */
	char *model;	/* Always nonnull. */

	/* name column. */
	char *name;	/* Always nonnull. */

	/* schema column. */
	char *schema;

	/* sid column. */
	struct uuid *sid;
	size_t n_sid;
};

enum serverrec_database_column_id {
    SERVERREC_DATABASE_COL_CID,
    SERVERREC_DATABASE_COL_CONNECTED,
    SERVERREC_DATABASE_COL_INDEX,
    SERVERREC_DATABASE_COL_LEADER,
    SERVERREC_DATABASE_COL_MODEL,
    SERVERREC_DATABASE_COL_NAME,
    SERVERREC_DATABASE_COL_SCHEMA,
    SERVERREC_DATABASE_COL_SID,
    SERVERREC_DATABASE_N_COLUMNS
};

#define serverrec_database_col_index (serverrec_database_columns[SERVERREC_DATABASE_COL_INDEX])
#define serverrec_database_col_name (serverrec_database_columns[SERVERREC_DATABASE_COL_NAME])
#define serverrec_database_col_cid (serverrec_database_columns[SERVERREC_DATABASE_COL_CID])
#define serverrec_database_col_connected (serverrec_database_columns[SERVERREC_DATABASE_COL_CONNECTED])
#define serverrec_database_col_sid (serverrec_database_columns[SERVERREC_DATABASE_COL_SID])
#define serverrec_database_col_model (serverrec_database_columns[SERVERREC_DATABASE_COL_MODEL])
#define serverrec_database_col_leader (serverrec_database_columns[SERVERREC_DATABASE_COL_LEADER])
#define serverrec_database_col_schema (serverrec_database_columns[SERVERREC_DATABASE_COL_SCHEMA])

extern struct ovsdb_idl_column serverrec_database_columns[SERVERREC_DATABASE_N_COLUMNS];

const struct serverrec_database_table *serverrec_database_table_get(const struct ovsdb_idl *);
const struct serverrec_database *serverrec_database_table_first(const struct serverrec_database_table *);

#define SERVERREC_DATABASE_TABLE_FOR_EACH(ROW, TABLE) \
        for ((ROW) = serverrec_database_table_first(TABLE); \
             (ROW); \
             (ROW) = serverrec_database_next(ROW))
#define SERVERREC_DATABASE_TABLE_FOR_EACH_SAFE(ROW, NEXT, TABLE) \
        for ((ROW) = serverrec_database_table_first(TABLE); \
             (ROW) ? ((NEXT) = serverrec_database_next(ROW), 1) : 0; \
             (ROW) = (NEXT))

const struct serverrec_database *serverrec_database_get_for_uuid(const struct ovsdb_idl *, const struct uuid *);
const struct serverrec_database *serverrec_database_first(const struct ovsdb_idl *);
const struct serverrec_database *serverrec_database_next(const struct serverrec_database *);
#define SERVERREC_DATABASE_FOR_EACH(ROW, IDL) \
        for ((ROW) = serverrec_database_first(IDL); \
             (ROW); \
             (ROW) = serverrec_database_next(ROW))
#define SERVERREC_DATABASE_FOR_EACH_SAFE(ROW, NEXT, IDL) \
        for ((ROW) = serverrec_database_first(IDL); \
             (ROW) ? ((NEXT) = serverrec_database_next(ROW), 1) : 0; \
             (ROW) = (NEXT))

unsigned int serverrec_database_get_seqno(const struct ovsdb_idl *);
unsigned int serverrec_database_row_get_seqno(const struct serverrec_database *row, enum ovsdb_idl_change change);
const struct serverrec_database *serverrec_database_track_get_first(const struct ovsdb_idl *);
const struct serverrec_database *serverrec_database_track_get_next(const struct serverrec_database *);
#define SERVERREC_DATABASE_FOR_EACH_TRACKED(ROW, IDL) \
        for ((ROW) = serverrec_database_track_get_first(IDL); \
             (ROW); \
             (ROW) = serverrec_database_track_get_next(ROW))

/* Returns true if 'row' was inserted since the last change tracking reset. */
static inline bool serverrec_database_is_new(const struct serverrec_database *row)
{
    return serverrec_database_row_get_seqno(row, OVSDB_IDL_CHANGE_MODIFY) == 0;
}

/* Returns true if 'row' was deleted since the last change tracking reset. */
static inline bool serverrec_database_is_deleted(const struct serverrec_database *row)
{
    return serverrec_database_row_get_seqno(row, OVSDB_IDL_CHANGE_DELETE) > 0;
}

void serverrec_database_index_destroy_row(const struct serverrec_database *);

struct serverrec_database *serverrec_database_index_find(struct ovsdb_idl_index *, const struct serverrec_database *);

int serverrec_database_index_compare(
    struct ovsdb_idl_index *, 
    const struct serverrec_database *, 
    const struct serverrec_database *);
struct ovsdb_idl_cursor serverrec_database_cursor_first(struct ovsdb_idl_index *);
struct ovsdb_idl_cursor serverrec_database_cursor_first_eq(
    struct ovsdb_idl_index *, const struct serverrec_database *);
struct ovsdb_idl_cursor serverrec_database_cursor_first_ge(
    struct ovsdb_idl_index *, const struct serverrec_database *);

struct serverrec_database *serverrec_database_cursor_data(struct ovsdb_idl_cursor *);

#define SERVERREC_DATABASE_FOR_EACH_RANGE(ROW, FROM, TO, INDEX) \
        for (struct ovsdb_idl_cursor cursor__ = serverrec_database_cursor_first_ge(INDEX, FROM); \
             (cursor__.position \
              && ((ROW) = serverrec_database_cursor_data(&cursor__), \
                  !(TO) || serverrec_database_index_compare(INDEX, ROW, TO) <= 0)); \
             ovsdb_idl_cursor_next(&cursor__))
#define SERVERREC_DATABASE_FOR_EACH_EQUAL(ROW, KEY, INDEX) \
        for (struct ovsdb_idl_cursor cursor__ = serverrec_database_cursor_first_eq(INDEX, KEY); \
             (cursor__.position \
              ? ((ROW) = serverrec_database_cursor_data(&cursor__), \
                 ovsdb_idl_cursor_next_eq(&cursor__), \
                 true) \
              : false); \
            )
#define SERVERREC_DATABASE_FOR_EACH_BYINDEX(ROW, INDEX) \
        for (struct ovsdb_idl_cursor cursor__ = serverrec_database_cursor_first(INDEX); \
             (cursor__.position \
              ? ((ROW) = serverrec_database_cursor_data(&cursor__), \
                 ovsdb_idl_cursor_next(&cursor__), \
                 true) \
              : false); \
            )

void serverrec_database_init(struct serverrec_database *);
void serverrec_database_delete(const struct serverrec_database *);
struct serverrec_database *serverrec_database_insert(struct ovsdb_idl_txn *);
bool serverrec_database_is_updated(const struct serverrec_database *, enum serverrec_database_column_id);

void serverrec_database_verify_cid(const struct serverrec_database *);
void serverrec_database_verify_connected(const struct serverrec_database *);
void serverrec_database_verify_index(const struct serverrec_database *);
void serverrec_database_verify_leader(const struct serverrec_database *);
void serverrec_database_verify_model(const struct serverrec_database *);
void serverrec_database_verify_name(const struct serverrec_database *);
void serverrec_database_verify_schema(const struct serverrec_database *);
void serverrec_database_verify_sid(const struct serverrec_database *);

const struct ovsdb_datum *serverrec_database_get_cid(const struct serverrec_database *, enum ovsdb_atomic_type key_type);
const struct ovsdb_datum *serverrec_database_get_connected(const struct serverrec_database *, enum ovsdb_atomic_type key_type);
const struct ovsdb_datum *serverrec_database_get_index(const struct serverrec_database *, enum ovsdb_atomic_type key_type);
const struct ovsdb_datum *serverrec_database_get_leader(const struct serverrec_database *, enum ovsdb_atomic_type key_type);
const struct ovsdb_datum *serverrec_database_get_model(const struct serverrec_database *, enum ovsdb_atomic_type key_type);
const struct ovsdb_datum *serverrec_database_get_name(const struct serverrec_database *, enum ovsdb_atomic_type key_type);
const struct ovsdb_datum *serverrec_database_get_schema(const struct serverrec_database *, enum ovsdb_atomic_type key_type);
const struct ovsdb_datum *serverrec_database_get_sid(const struct serverrec_database *, enum ovsdb_atomic_type key_type);

void serverrec_database_set_cid(const struct serverrec_database *, const struct uuid *cid, size_t n_cid);
void serverrec_database_set_connected(const struct serverrec_database *, bool connected);
void serverrec_database_set_index(const struct serverrec_database *, const int64_t *index, size_t n_index);
void serverrec_database_set_leader(const struct serverrec_database *, bool leader);
void serverrec_database_set_model(const struct serverrec_database *, const char *model);
void serverrec_database_set_name(const struct serverrec_database *, const char *name);
void serverrec_database_set_schema(const struct serverrec_database *, const char *schema);
void serverrec_database_set_sid(const struct serverrec_database *, const struct uuid *sid, size_t n_sid);

void serverrec_database_update_cid_addvalue(const struct serverrec_database *,  struct uuid );
void serverrec_database_update_cid_delvalue(const struct serverrec_database *,  struct uuid );
void serverrec_database_add_clause_cid(struct ovsdb_idl_condition *, enum ovsdb_function function, const struct uuid *cid, size_t n_cid);
void serverrec_database_set_condition(struct ovsdb_idl *, struct ovsdb_idl_condition *);
void serverrec_database_add_clause_connected(struct ovsdb_idl_condition *, enum ovsdb_function function, bool connected);
void serverrec_database_set_condition(struct ovsdb_idl *, struct ovsdb_idl_condition *);
void serverrec_database_update_index_addvalue(const struct serverrec_database *,  int64_t );
void serverrec_database_update_index_delvalue(const struct serverrec_database *,  int64_t );
void serverrec_database_add_clause_index(struct ovsdb_idl_condition *, enum ovsdb_function function, const int64_t *index, size_t n_index);
void serverrec_database_set_condition(struct ovsdb_idl *, struct ovsdb_idl_condition *);
void serverrec_database_add_clause_leader(struct ovsdb_idl_condition *, enum ovsdb_function function, bool leader);
void serverrec_database_set_condition(struct ovsdb_idl *, struct ovsdb_idl_condition *);
void serverrec_database_add_clause_model(struct ovsdb_idl_condition *, enum ovsdb_function function, const char *model);
void serverrec_database_set_condition(struct ovsdb_idl *, struct ovsdb_idl_condition *);
void serverrec_database_add_clause_name(struct ovsdb_idl_condition *, enum ovsdb_function function, const char *name);
void serverrec_database_set_condition(struct ovsdb_idl *, struct ovsdb_idl_condition *);
void serverrec_database_update_schema_addvalue(const struct serverrec_database *,  const char *);
void serverrec_database_update_schema_delvalue(const struct serverrec_database *,  const char *);
void serverrec_database_add_clause_schema(struct ovsdb_idl_condition *, enum ovsdb_function function, const char *schema);
void serverrec_database_set_condition(struct ovsdb_idl *, struct ovsdb_idl_condition *);
void serverrec_database_update_sid_addvalue(const struct serverrec_database *,  struct uuid );
void serverrec_database_update_sid_delvalue(const struct serverrec_database *,  struct uuid );
void serverrec_database_add_clause_sid(struct ovsdb_idl_condition *, enum ovsdb_function function, const struct uuid *sid, size_t n_sid);
void serverrec_database_set_condition(struct ovsdb_idl *, struct ovsdb_idl_condition *);

struct serverrec_database *serverrec_database_index_init_row(struct ovsdb_idl_index *);
void serverrec_database_index_set_cid(const struct serverrec_database *,
const struct uuid *cid, size_t n_cid);
void serverrec_database_index_set_connected(const struct serverrec_database *,
bool connected);
void serverrec_database_index_set_index(const struct serverrec_database *,
const int64_t *index, size_t n_index);
void serverrec_database_index_set_leader(const struct serverrec_database *,
bool leader);
void serverrec_database_index_set_model(const struct serverrec_database *,
const char *model);
void serverrec_database_index_set_name(const struct serverrec_database *,
const char *name);
void serverrec_database_index_set_schema(const struct serverrec_database *,
const char *schema);
void serverrec_database_index_set_sid(const struct serverrec_database *,
const struct uuid *sid, size_t n_sid);

enum serverrec_table_id {
    SERVERREC_TABLE_DATABASE,
    SERVERREC_N_TABLES
};

#define serverrec_table_database (serverrec_table_classes[SERVERREC_TABLE_DATABASE])

extern struct ovsdb_idl_table_class serverrec_table_classes[SERVERREC_N_TABLES];

extern struct ovsdb_idl_class serverrec_idl_class;

const char * serverrec_get_db_version(void);

#ifdef  __cplusplus
}
#endif

#endif /* SERVERREC_IDL_HEADER */
