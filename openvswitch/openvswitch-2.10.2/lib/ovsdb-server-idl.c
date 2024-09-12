/* Generated automatically -- do not modify!    -*- buffer-read-only: t -*- */

#include <config.h>
#include "lib/ovsdb-server-idl.h"
#include <limits.h>
#include "ovs-thread.h"
#include "ovsdb-data.h"
#include "ovsdb-error.h"
#include "util.h"





static struct serverrec_database *
serverrec_database_cast(const struct ovsdb_idl_row *row)
{
    return row ? CONTAINER_OF(row, struct serverrec_database, header_) : NULL;
}

/* Database table. */

const struct serverrec_database_table *
serverrec_database_table_get(const struct ovsdb_idl *idl)
{
    return (const struct serverrec_database_table *) idl;
}

const struct serverrec_database *
serverrec_database_table_first(const struct serverrec_database_table *table)
{
    const struct ovsdb_idl *idl = (const struct ovsdb_idl *) table;
    return serverrec_database_first(idl);
}


static void
serverrec_database_parse_cid(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct serverrec_database *row = serverrec_database_cast(row_);
    size_t n = MIN(1, datum->n);
    row->cid = NULL;
    row->n_cid = 0;
    for (size_t i = 0; i < n; i++) {
        if (!row->n_cid) {
            row->cid = xmalloc(n * sizeof *row->cid);
        }
        row->cid[row->n_cid] = datum->keys[i].uuid;
        row->n_cid++;
    }
}

static void
serverrec_database_parse_connected(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct serverrec_database *row = serverrec_database_cast(row_);

    if (datum->n >= 1) {
        row->connected = datum->keys[0].boolean;
    } else {
        row->connected = false;
    }
}

static void
serverrec_database_parse_index(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct serverrec_database *row = serverrec_database_cast(row_);
    size_t n = MIN(1, datum->n);
    row->index = NULL;
    row->n_index = 0;
    for (size_t i = 0; i < n; i++) {
        if (!row->n_index) {
            row->index = xmalloc(n * sizeof *row->index);
        }
        row->index[row->n_index] = datum->keys[i].integer;
        row->n_index++;
    }
}

static void
serverrec_database_parse_leader(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct serverrec_database *row = serverrec_database_cast(row_);

    if (datum->n >= 1) {
        row->leader = datum->keys[0].boolean;
    } else {
        row->leader = false;
    }
}

static void
serverrec_database_parse_model(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct serverrec_database *row = serverrec_database_cast(row_);

    if (datum->n >= 1) {
        row->model = datum->keys[0].string;
    } else {
        row->model = "";
    }
}

static void
serverrec_database_parse_name(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct serverrec_database *row = serverrec_database_cast(row_);

    if (datum->n >= 1) {
        row->name = datum->keys[0].string;
    } else {
        row->name = "";
    }
}

static void
serverrec_database_parse_schema(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct serverrec_database *row = serverrec_database_cast(row_);

    if (datum->n >= 1) {
        row->schema = datum->keys[0].string;
    } else {
        row->schema = NULL;
    }
}

static void
serverrec_database_parse_sid(struct ovsdb_idl_row *row_, const struct ovsdb_datum *datum)
{
    struct serverrec_database *row = serverrec_database_cast(row_);
    size_t n = MIN(1, datum->n);
    row->sid = NULL;
    row->n_sid = 0;
    for (size_t i = 0; i < n; i++) {
        if (!row->n_sid) {
            row->sid = xmalloc(n * sizeof *row->sid);
        }
        row->sid[row->n_sid] = datum->keys[i].uuid;
        row->n_sid++;
    }
}

static void
serverrec_database_unparse_cid(struct ovsdb_idl_row *row_)
{
    struct serverrec_database *row = serverrec_database_cast(row_);
    free(row->cid);
}

static void
serverrec_database_unparse_connected(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
serverrec_database_unparse_index(struct ovsdb_idl_row *row_)
{
    struct serverrec_database *row = serverrec_database_cast(row_);
    free(row->index);
}

static void
serverrec_database_unparse_leader(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
serverrec_database_unparse_model(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
serverrec_database_unparse_name(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
serverrec_database_unparse_schema(struct ovsdb_idl_row *row OVS_UNUSED)
{
    /* Nothing to do. */
}

static void
serverrec_database_unparse_sid(struct ovsdb_idl_row *row_)
{
    struct serverrec_database *row = serverrec_database_cast(row_);
    free(row->sid);
}

static void
serverrec_database_init__(struct ovsdb_idl_row *row)
{
    serverrec_database_init(serverrec_database_cast(row));
}

/* Clears the contents of 'row' in table "Database". */
void
serverrec_database_init(struct serverrec_database *row)
{
    memset(row, 0, sizeof *row); 
    row->model = "";
    row->name = "";
}

/* Searches table "Database" in 'idl' for a row with UUID 'uuid'.  Returns
 * a pointer to the row if there is one, otherwise a null pointer.  */
const struct serverrec_database *
serverrec_database_get_for_uuid(const struct ovsdb_idl *idl, const struct uuid *uuid)
{
    return serverrec_database_cast(ovsdb_idl_get_row_for_uuid(idl, &serverrec_table_database, uuid));
}

/* Returns a row in table "Database" in 'idl', or a null pointer if that
 * table is empty.
 *
 * Database tables are internally maintained as hash tables, so adding or
 * removing rows while traversing the same table can cause some rows to be
 * visited twice or not at apply. */
const struct serverrec_database *
serverrec_database_first(const struct ovsdb_idl *idl)
{
    return serverrec_database_cast(ovsdb_idl_first_row(idl, &serverrec_table_database));
}

/* Returns a row following 'row' within its table, or a null pointer if 'row'
 * is the last row in its table. */
const struct serverrec_database *
serverrec_database_next(const struct serverrec_database *row)
{
    return serverrec_database_cast(ovsdb_idl_next_row(&row->header_));
}

unsigned int serverrec_database_get_seqno(const struct ovsdb_idl *idl)
{
    return ovsdb_idl_table_get_seqno(idl, &serverrec_table_database);
}

unsigned int serverrec_database_row_get_seqno(const struct serverrec_database *row, enum ovsdb_idl_change change)
{
    return ovsdb_idl_row_get_seqno(&row->header_, change);
}

const struct serverrec_database *
serverrec_database_track_get_first(const struct ovsdb_idl *idl)
{
    return serverrec_database_cast(ovsdb_idl_track_get_first(idl, &serverrec_table_database));
}

const struct serverrec_database
*serverrec_database_track_get_next(const struct serverrec_database *row)
{
    return serverrec_database_cast(ovsdb_idl_track_get_next(&row->header_));
}


/* Deletes 'row' from table "Database".  'row' may be freed, so it must not be
 * accessed afterward.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
serverrec_database_delete(const struct serverrec_database *row)
{
    ovsdb_idl_txn_delete(&row->header_);
}

/* Inserts and returns a new row in the table "Database" in the database
 * with open transaction 'txn'.
 *
 * The new row is assigned a randomly generated provisional UUID.
 * ovsdb-server will assign a different UUID when 'txn' is committed,
 * but the IDL will replace any uses of the provisional UUID in the
 * data to be to be committed by the UUID assigned by ovsdb-server. */
struct serverrec_database *
serverrec_database_insert(struct ovsdb_idl_txn *txn)
{
    return serverrec_database_cast(ovsdb_idl_txn_insert(txn, &serverrec_table_database, NULL));
}

bool
serverrec_database_is_updated(const struct serverrec_database *row, enum serverrec_database_column_id column)
{
    return ovsdb_idl_track_is_updated(&row->header_, &serverrec_database_columns[column]);
}

/* Causes the original contents of column "cid" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "cid" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "cid" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "cid" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     serverrec_database_insert()).
 *
 *   - If "cid" has already been modified (with
 *     serverrec_database_set_cid()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * serverrec_database_set_cid() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
serverrec_database_verify_cid(const struct serverrec_database *row)
{
    ovsdb_idl_txn_verify(&row->header_, &serverrec_database_col_cid);
}

/* Causes the original contents of column "connected" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "connected" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "connected" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "connected" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     serverrec_database_insert()).
 *
 *   - If "connected" has already been modified (with
 *     serverrec_database_set_connected()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * serverrec_database_set_connected() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
serverrec_database_verify_connected(const struct serverrec_database *row)
{
    ovsdb_idl_txn_verify(&row->header_, &serverrec_database_col_connected);
}

/* Causes the original contents of column "index" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "index" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "index" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "index" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     serverrec_database_insert()).
 *
 *   - If "index" has already been modified (with
 *     serverrec_database_set_index()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * serverrec_database_set_index() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
serverrec_database_verify_index(const struct serverrec_database *row)
{
    ovsdb_idl_txn_verify(&row->header_, &serverrec_database_col_index);
}

/* Causes the original contents of column "leader" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "leader" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "leader" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "leader" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     serverrec_database_insert()).
 *
 *   - If "leader" has already been modified (with
 *     serverrec_database_set_leader()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * serverrec_database_set_leader() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
serverrec_database_verify_leader(const struct serverrec_database *row)
{
    ovsdb_idl_txn_verify(&row->header_, &serverrec_database_col_leader);
}

/* Causes the original contents of column "model" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "model" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "model" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "model" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     serverrec_database_insert()).
 *
 *   - If "model" has already been modified (with
 *     serverrec_database_set_model()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * serverrec_database_set_model() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
serverrec_database_verify_model(const struct serverrec_database *row)
{
    ovsdb_idl_txn_verify(&row->header_, &serverrec_database_col_model);
}

/* Causes the original contents of column "name" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "name" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "name" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "name" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     serverrec_database_insert()).
 *
 *   - If "name" has already been modified (with
 *     serverrec_database_set_name()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * serverrec_database_set_name() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
serverrec_database_verify_name(const struct serverrec_database *row)
{
    ovsdb_idl_txn_verify(&row->header_, &serverrec_database_col_name);
}

/* Causes the original contents of column "schema" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "schema" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "schema" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "schema" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     serverrec_database_insert()).
 *
 *   - If "schema" has already been modified (with
 *     serverrec_database_set_schema()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * serverrec_database_set_schema() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
serverrec_database_verify_schema(const struct serverrec_database *row)
{
    ovsdb_idl_txn_verify(&row->header_, &serverrec_database_col_schema);
}

/* Causes the original contents of column "sid" in 'row' to be
 * verified as a prerequisite to completing the transaction.  That is, if
 * "sid" in 'row' changed (or if 'row' was deleted) between the
 * time that the IDL originally read its contents and the time that the
 * transaction aborts and ovsdb_idl_txn_commit() returns TXN_TRY_AGAIN.
 *
 * The intention is that, to ensure that no transaction commits based on dirty
 * reads, an application should call this function any time "sid" is
 * read as part of a read-modify-write operation.
 *
 * In some cases this function reduces to a no-op, because the current value
 * of "sid" is already known:
 *
 *   - If 'row' is a row created by the current transaction (returned by
 *     serverrec_database_insert()).
 *
 *   - If "sid" has already been modified (with
 *     serverrec_database_set_sid()) within the current transaction.
 *
 * Because of the latter property, always call this function *before*
 * serverrec_database_set_sid() for a given read-modify-write.
 *
 * The caller must have started a transaction with ovsdb_idl_txn_create(). */
void
serverrec_database_verify_sid(const struct serverrec_database *row)
{
    ovsdb_idl_txn_verify(&row->header_, &serverrec_database_col_sid);
}

/* Returns the "cid" column's value from the "Database" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes cid's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "cid" member in serverrec_database. */
const struct ovsdb_datum *
serverrec_database_get_cid(const struct serverrec_database *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &serverrec_database_col_cid);
}

/* Returns the "connected" column's value from the "Database" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes connected's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "connected" member in serverrec_database. */
const struct ovsdb_datum *
serverrec_database_get_connected(const struct serverrec_database *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &serverrec_database_col_connected);
}

/* Returns the "index" column's value from the "Database" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_INTEGER.
 * (This helps to avoid silent bugs if someone changes index's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "index" member in serverrec_database. */
const struct ovsdb_datum *
serverrec_database_get_index(const struct serverrec_database *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_INTEGER);
    return ovsdb_idl_read(&row->header_, &serverrec_database_col_index);
}

/* Returns the "leader" column's value from the "Database" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_BOOLEAN.
 * (This helps to avoid silent bugs if someone changes leader's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "leader" member in serverrec_database. */
const struct ovsdb_datum *
serverrec_database_get_leader(const struct serverrec_database *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_BOOLEAN);
    return ovsdb_idl_read(&row->header_, &serverrec_database_col_leader);
}

/* Returns the "model" column's value from the "Database" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes model's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "model" member in serverrec_database. */
const struct ovsdb_datum *
serverrec_database_get_model(const struct serverrec_database *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &serverrec_database_col_model);
}

/* Returns the "name" column's value from the "Database" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes name's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "name" member in serverrec_database. */
const struct ovsdb_datum *
serverrec_database_get_name(const struct serverrec_database *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &serverrec_database_col_name);
}

/* Returns the "schema" column's value from the "Database" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_STRING.
 * (This helps to avoid silent bugs if someone changes schema's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "schema" member in serverrec_database. */
const struct ovsdb_datum *
serverrec_database_get_schema(const struct serverrec_database *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_STRING);
    return ovsdb_idl_read(&row->header_, &serverrec_database_col_schema);
}

/* Returns the "sid" column's value from the "Database" table in 'row'
 * as a struct ovsdb_datum.  This is useful occasionally: for example,
 * ovsdb_datum_find_key() is an easier and more efficient way to search
 * for a given key than implementing the same operation on the "cooked"
 * form in 'row'.
 *
 * 'key_type' must be OVSDB_TYPE_UUID.
 * (This helps to avoid silent bugs if someone changes sid's
 * type without updating the caller.)
 *
 * The caller must not modify or free the returned value.
 *
 * Various kinds of changes can invalidate the returned value: modifying
 * 'column' within 'row', deleting 'row', or completing an ongoing transaction.
 * If the returned value is needed for a long time, it is best to make a copy
 * of it with ovsdb_datum_clone().
 *
 * This function is rarely useful, since it is easier to access the value
 * directly through the "sid" member in serverrec_database. */
const struct ovsdb_datum *
serverrec_database_get_sid(const struct serverrec_database *row,
	enum ovsdb_atomic_type key_type OVS_UNUSED)
{
    ovs_assert(key_type == OVSDB_TYPE_UUID);
    return ovsdb_idl_read(&row->header_, &serverrec_database_col_sid);
}

/* Sets the "cid" column from the "Database" table in 'row' to
 * the 'cid' set with 'n_cid' entries.
 *
 * 'n_cid' may be 0 or 1; if it is 0, then 'cid'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_set_cid(const struct serverrec_database *row, const struct uuid *cid, size_t n_cid)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_cid) {
        datum.n = 1;
        datum.keys = &key;
        key.uuid = *cid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &serverrec_database_col_cid, &datum);
}

/* Sets the "connected" column from the "Database" table in 'row' to
 * 'connected'.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_set_connected(const struct serverrec_database *row, bool connected)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = connected;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &serverrec_database_col_connected, &datum);
}

/* Sets the "index" column from the "Database" table in 'row' to
 * the 'index' set with 'n_index' entries.
 *
 * 'n_index' may be 0 or 1; if it is 0, then 'index'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_set_index(const struct serverrec_database *row, const int64_t *index, size_t n_index)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_index) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *index;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &serverrec_database_col_index, &datum);
}

/* Sets the "leader" column from the "Database" table in 'row' to
 * 'leader'.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_set_leader(const struct serverrec_database *row, bool leader)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = leader;
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &serverrec_database_col_leader, &datum);
}

/* Sets the "model" column from the "Database" table in 'row' to
 * 'model'.
 *
 * Argument constraints: either "clustered" or "standalone"
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_set_model(const struct serverrec_database *row, const char *model)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, model);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &serverrec_database_col_model, &datum);
}

/* Sets the "name" column from the "Database" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_set_name(const struct serverrec_database *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &serverrec_database_col_name, &datum);
}

/* Sets the "schema" column from the "Database" table in 'row' to
 * the 'schema' set.
 *
 * If "schema" is null, the column will be the empty set,
 * otherwise it will contain the specified value.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_set_schema(const struct serverrec_database *row, const char *schema)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (schema) {
        datum.n = 1;
        datum.keys = &key;
        key.string = CONST_CAST(char *, schema);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &serverrec_database_col_schema, &datum);
}

/* Sets the "sid" column from the "Database" table in 'row' to
 * the 'sid' set with 'n_sid' entries.
 *
 * 'n_sid' may be 0 or 1; if it is 0, then 'sid'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_set_sid(const struct serverrec_database *row, const struct uuid *sid, size_t n_sid)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_sid) {
        datum.n = 1;
        datum.keys = &key;
        key.uuid = *sid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_txn_write_clone(&row->header_, &serverrec_database_col_sid, &datum);
}

/* Adds the value 'new_value' to the "cid" set column from the "Database" table
 * in 'row'.
 *
 */
void
serverrec_database_update_cid_addvalue(const struct serverrec_database *row, struct uuid new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = new_value;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &serverrec_database_col_cid,
                                    datum);
}

/* Deletes the value 'delete_value' from the "cid" set column from the
 * "Database" table in 'row'.
 *
 */
void
serverrec_database_update_cid_delvalue(const struct serverrec_database *row, struct uuid delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = delete_value;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &serverrec_database_col_cid,
                                    datum);
}

/* Adds the value 'new_value' to the "index" set column from the "Database" table
 * in 'row'.
 *
 */
void
serverrec_database_update_index_addvalue(const struct serverrec_database *row, int64_t new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].integer = new_value;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &serverrec_database_col_index,
                                    datum);
}

/* Deletes the value 'delete_value' from the "index" set column from the
 * "Database" table in 'row'.
 *
 */
void
serverrec_database_update_index_delvalue(const struct serverrec_database *row, int64_t delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].integer = delete_value;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &serverrec_database_col_index,
                                    datum);
}

/* Adds the value 'new_value' to the "schema" set column from the "Database" table
 * in 'row'.
 *
 */
void
serverrec_database_update_schema_addvalue(const struct serverrec_database *row, const char *new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(new_value);

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &serverrec_database_col_schema,
                                    datum);
}

/* Deletes the value 'delete_value' from the "schema" set column from the
 * "Database" table in 'row'.
 *
 */
void
serverrec_database_update_schema_delvalue(const struct serverrec_database *row, const char *delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].string = xstrdup(delete_value);

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &serverrec_database_col_schema,
                                    datum);
}

/* Adds the value 'new_value' to the "sid" set column from the "Database" table
 * in 'row'.
 *
 */
void
serverrec_database_update_sid_addvalue(const struct serverrec_database *row, struct uuid new_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = new_value;

    ovsdb_idl_txn_write_partial_set(&row->header_,
                                    &serverrec_database_col_sid,
                                    datum);
}

/* Deletes the value 'delete_value' from the "sid" set column from the
 * "Database" table in 'row'.
 *
 */
void
serverrec_database_update_sid_delvalue(const struct serverrec_database *row, struct uuid delete_value)
{
    struct ovsdb_datum *datum;

    datum = xmalloc(sizeof *datum);
    datum->n = 1;
    datum->keys = xmalloc(datum->n * sizeof *datum->values);
    datum->values = NULL;

    datum->keys[0].uuid = delete_value;

    ovsdb_idl_txn_delete_partial_set(&row->header_,
                                    &serverrec_database_col_sid,
                                    datum);
}

/* Sets the "cid" column from the "Database" table in 'row' to
 * the 'cid' set with 'n_cid' entries.
 *
 * 'n_cid' may be 0 or 1; if it is 0, then 'cid'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_add_clause_cid(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct uuid *cid, size_t n_cid)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_cid) {
        datum.n = 1;
        datum.keys = &key;
        key.uuid = *cid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &serverrec_database_col_cid,
                          &datum);
}

/* Sets the "connected" column from the "Database" table in 'row' to
 * 'connected'.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_add_clause_connected(struct ovsdb_idl_condition *cond, enum ovsdb_function function, bool connected)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = connected;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &serverrec_database_col_connected,
                          &datum);
}

/* Sets the "index" column from the "Database" table in 'row' to
 * the 'index' set with 'n_index' entries.
 *
 * 'n_index' may be 0 or 1; if it is 0, then 'index'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_add_clause_index(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const int64_t *index, size_t n_index)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_index) {
        datum.n = 1;
        datum.keys = &key;
        key.integer = *index;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &serverrec_database_col_index,
                          &datum);
}

/* Sets the "leader" column from the "Database" table in 'row' to
 * 'leader'.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_add_clause_leader(struct ovsdb_idl_condition *cond, enum ovsdb_function function, bool leader)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.boolean = leader;
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &serverrec_database_col_leader,
                          &datum);
}

/* Sets the "model" column from the "Database" table in 'row' to
 * 'model'.
 *
 * Argument constraints: either "clustered" or "standalone"
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_add_clause_model(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *model)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, model);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &serverrec_database_col_model,
                          &datum);
}

/* Sets the "name" column from the "Database" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_add_clause_name(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    datum.n = 1;
    datum.keys = &key;
    key.string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &serverrec_database_col_name,
                          &datum);
}

/* Sets the "schema" column from the "Database" table in 'row' to
 * the 'schema' set.
 *
 * If "schema" is null, the column will be the empty set,
 * otherwise it will contain the specified value.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_add_clause_schema(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const char *schema)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (schema) {
        datum.n = 1;
        datum.keys = &key;
        key.string = CONST_CAST(char *, schema);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &serverrec_database_col_schema,
                          &datum);
}

/* Sets the "sid" column from the "Database" table in 'row' to
 * the 'sid' set with 'n_sid' entries.
 *
 * 'n_sid' may be 0 or 1; if it is 0, then 'sid'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_add_clause_sid(struct ovsdb_idl_condition *cond, enum ovsdb_function function, const struct uuid *sid, size_t n_sid)
{
    struct ovsdb_datum datum;
    union ovsdb_atom key;

    if (n_sid) {
        datum.n = 1;
        datum.keys = &key;
        key.uuid = *sid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_condition_add_clause(cond,
                          function,
                          &serverrec_database_col_sid,
                          &datum);
}

/* Destroy 'row' of kind "Database". The row must have been
 * created with ovsdb_idl_index_init_row.
 */
void
serverrec_database_index_destroy_row(const struct serverrec_database *row)
{
    ovsdb_idl_index_destroy_row(&row->header_);
}
        

/* Creates a new row of kind "Database". */
struct serverrec_database *
serverrec_database_index_init_row(struct ovsdb_idl_index *index)
{
    ovs_assert(index->table->class_ == &serverrec_table_database);
    return ALIGNED_CAST(struct serverrec_database *, ovsdb_idl_index_init_row(index));
}

struct serverrec_database *
serverrec_database_index_find(struct ovsdb_idl_index *index, const struct serverrec_database *target)
{
    ovs_assert(index->table->class_ == &serverrec_table_database);
    return serverrec_database_cast(ovsdb_idl_index_find(index, &target->header_));
}

/* Compares 'a' to 'b' and returns a strcmp()-type result. */
int
serverrec_database_index_compare(
    struct ovsdb_idl_index *index, 
    const struct serverrec_database *a, 
    const struct serverrec_database *b)
{
    return ovsdb_idl_index_compare(index, &a->header_, &b->header_);
}

struct ovsdb_idl_cursor
serverrec_database_cursor_first(struct ovsdb_idl_index *index)
{
    ovs_assert(index->table->class_ == &serverrec_table_database);
    return ovsdb_idl_cursor_first(index);
}

struct ovsdb_idl_cursor
serverrec_database_cursor_first_eq(
    struct ovsdb_idl_index *index, const struct serverrec_database *target)
{
    ovs_assert(index->table->class_ == &serverrec_table_database);
    return ovsdb_idl_cursor_first_eq(index, &target->header_);
}

struct ovsdb_idl_cursor
serverrec_database_cursor_first_ge(
    struct ovsdb_idl_index *index, const struct serverrec_database *target)
{
    ovs_assert(index->table->class_ == &serverrec_table_database);
    return ovsdb_idl_cursor_first_ge(index, &target->header_);
}

struct serverrec_database *
serverrec_database_cursor_data(struct ovsdb_idl_cursor *cursor)
{
    return serverrec_database_cast(ovsdb_idl_cursor_data(cursor));
}


/* Sets the "cid" column from the "Database" table in 'row' to
 * the 'cid' set with 'n_cid' entries.
 *
 * 'n_cid' may be 0 or 1; if it is 0, then 'cid'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_index_set_cid(const struct serverrec_database *row, const struct uuid *cid, size_t n_cid)
{
    struct ovsdb_datum datum;
    union ovsdb_atom *key = xmalloc(sizeof(union ovsdb_atom));

    if (n_cid) {
        datum.n = 1;
        datum.keys = key;
        key->uuid = *cid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_index_write(CONST_CAST(struct ovsdb_idl_row *, &row->header_), &serverrec_database_columns[ SERVERREC_DATABASE_COL_CID ], &datum, &serverrec_table_classes[SERVERREC_TABLE_DATABASE]);
}

/* Sets the "connected" column from the "Database" table in 'row' to
 * 'connected'.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_index_set_connected(const struct serverrec_database *row, bool connected)
{
    struct ovsdb_datum datum;
    union ovsdb_atom *key = xmalloc(sizeof(union ovsdb_atom));

    datum.n = 1;
    datum.keys = key;
    key->boolean = connected;
    datum.values = NULL;
    ovsdb_idl_index_write(CONST_CAST(struct ovsdb_idl_row *, &row->header_), &serverrec_database_columns[ SERVERREC_DATABASE_COL_CONNECTED ], &datum, &serverrec_table_classes[SERVERREC_TABLE_DATABASE]);
}

/* Sets the "index" column from the "Database" table in 'row' to
 * the 'index' set with 'n_index' entries.
 *
 * 'n_index' may be 0 or 1; if it is 0, then 'index'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_index_set_index(const struct serverrec_database *row, const int64_t *index, size_t n_index)
{
    struct ovsdb_datum datum;
    union ovsdb_atom *key = xmalloc(sizeof(union ovsdb_atom));

    if (n_index) {
        datum.n = 1;
        datum.keys = key;
        key->integer = *index;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_index_write(CONST_CAST(struct ovsdb_idl_row *, &row->header_), &serverrec_database_columns[ SERVERREC_DATABASE_COL_INDEX ], &datum, &serverrec_table_classes[SERVERREC_TABLE_DATABASE]);
}

/* Sets the "leader" column from the "Database" table in 'row' to
 * 'leader'.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_index_set_leader(const struct serverrec_database *row, bool leader)
{
    struct ovsdb_datum datum;
    union ovsdb_atom *key = xmalloc(sizeof(union ovsdb_atom));

    datum.n = 1;
    datum.keys = key;
    key->boolean = leader;
    datum.values = NULL;
    ovsdb_idl_index_write(CONST_CAST(struct ovsdb_idl_row *, &row->header_), &serverrec_database_columns[ SERVERREC_DATABASE_COL_LEADER ], &datum, &serverrec_table_classes[SERVERREC_TABLE_DATABASE]);
}

/* Sets the "model" column from the "Database" table in 'row' to
 * 'model'.
 *
 * Argument constraints: either "clustered" or "standalone"
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_index_set_model(const struct serverrec_database *row, const char *model)
{
    struct ovsdb_datum datum;
    union ovsdb_atom *key = xmalloc(sizeof(union ovsdb_atom));

    datum.n = 1;
    datum.keys = key;
    key->string = CONST_CAST(char *, model);
    datum.values = NULL;
    ovsdb_idl_index_write(CONST_CAST(struct ovsdb_idl_row *, &row->header_), &serverrec_database_columns[ SERVERREC_DATABASE_COL_MODEL ], &datum, &serverrec_table_classes[SERVERREC_TABLE_DATABASE]);
}

/* Sets the "name" column from the "Database" table in 'row' to
 * 'name'.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_index_set_name(const struct serverrec_database *row, const char *name)
{
    struct ovsdb_datum datum;
    union ovsdb_atom *key = xmalloc(sizeof(union ovsdb_atom));

    datum.n = 1;
    datum.keys = key;
    key->string = CONST_CAST(char *, name);
    datum.values = NULL;
    ovsdb_idl_index_write(CONST_CAST(struct ovsdb_idl_row *, &row->header_), &serverrec_database_columns[ SERVERREC_DATABASE_COL_NAME ], &datum, &serverrec_table_classes[SERVERREC_TABLE_DATABASE]);
}

/* Sets the "schema" column from the "Database" table in 'row' to
 * the 'schema' set.
 *
 * If "schema" is null, the column will be the empty set,
 * otherwise it will contain the specified value.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_index_set_schema(const struct serverrec_database *row, const char *schema)
{
    struct ovsdb_datum datum;
    union ovsdb_atom *key = xmalloc(sizeof (union ovsdb_atom));

    if (schema) {
        datum.n = 1;
        datum.keys = key;
        key->string = CONST_CAST(char *, schema);
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_index_write(CONST_CAST(struct ovsdb_idl_row *, &row->header_), &serverrec_database_columns[ SERVERREC_DATABASE_COL_SCHEMA ], &datum, &serverrec_table_classes[SERVERREC_TABLE_DATABASE]);
}

/* Sets the "sid" column from the "Database" table in 'row' to
 * the 'sid' set with 'n_sid' entries.
 *
 * 'n_sid' may be 0 or 1; if it is 0, then 'sid'
 * may be NULL.
 *
 * The caller retains ownership of the arguments. */
void
serverrec_database_index_set_sid(const struct serverrec_database *row, const struct uuid *sid, size_t n_sid)
{
    struct ovsdb_datum datum;
    union ovsdb_atom *key = xmalloc(sizeof(union ovsdb_atom));

    if (n_sid) {
        datum.n = 1;
        datum.keys = key;
        key->uuid = *sid;
    } else {
        datum.n = 0;
        datum.keys = NULL;
    }
    datum.values = NULL;
    ovsdb_idl_index_write(CONST_CAST(struct ovsdb_idl_row *, &row->header_), &serverrec_database_columns[ SERVERREC_DATABASE_COL_SID ], &datum, &serverrec_table_classes[SERVERREC_TABLE_DATABASE]);
}

struct ovsdb_idl_column serverrec_database_columns[SERVERREC_DATABASE_N_COLUMNS];

void
serverrec_database_set_condition(struct ovsdb_idl *idl, struct ovsdb_idl_condition *condition)
{
    ovsdb_idl_set_condition(idl, &serverrec_table_database, condition);
}
static union ovsdb_atom Database_col_model_key_enum_keys[2] = {
    { .string = "clustered" },
    { .string = "standalone" },
};
static struct ovsdb_datum Database_col_model_key_enum = {
    .n = 2,
    .keys = Database_col_model_key_enum_keys,
};

struct ovsdb_idl_column serverrec_database_columns[SERVERREC_DATABASE_N_COLUMNS] = {
    [SERVERREC_DATABASE_COL_CID] = {
         .name = "cid",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .is_mutable = true,
         .is_synthetic = false,
         .parse = serverrec_database_parse_cid,
         .unparse = serverrec_database_unparse_cid,
    },

    [SERVERREC_DATABASE_COL_CONNECTED] = {
         .name = "connected",
         .type = {
            .key = {
               .type = OVSDB_TYPE_BOOLEAN,
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .is_mutable = true,
         .is_synthetic = false,
         .parse = serverrec_database_parse_connected,
         .unparse = serverrec_database_unparse_connected,
    },

    [SERVERREC_DATABASE_COL_INDEX] = {
         .name = "index",
         .type = {
            .key = {
               .type = OVSDB_TYPE_INTEGER,
               .integer = { .min = INT64_MIN, .max = INT64_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .is_mutable = true,
         .is_synthetic = false,
         .parse = serverrec_database_parse_index,
         .unparse = serverrec_database_unparse_index,
    },

    [SERVERREC_DATABASE_COL_LEADER] = {
         .name = "leader",
         .type = {
            .key = {
               .type = OVSDB_TYPE_BOOLEAN,
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .is_mutable = true,
         .is_synthetic = false,
         .parse = serverrec_database_parse_leader,
         .unparse = serverrec_database_unparse_leader,
    },

    [SERVERREC_DATABASE_COL_MODEL] = {
         .name = "model",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .enum_ = &Database_col_model_key_enum,
               .string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .is_mutable = true,
         .is_synthetic = false,
         .parse = serverrec_database_parse_model,
         .unparse = serverrec_database_unparse_model,
    },

    [SERVERREC_DATABASE_COL_NAME] = {
         .name = "name",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 1,
            .n_max = 1,
         },
         .is_mutable = true,
         .is_synthetic = false,
         .parse = serverrec_database_parse_name,
         .unparse = serverrec_database_unparse_name,
    },

    [SERVERREC_DATABASE_COL_SCHEMA] = {
         .name = "schema",
         .type = {
            .key = {
               .type = OVSDB_TYPE_STRING,
               .string = { .minLen = 0, .maxLen = UINT_MAX },
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .is_mutable = true,
         .is_synthetic = false,
         .parse = serverrec_database_parse_schema,
         .unparse = serverrec_database_unparse_schema,
    },

    [SERVERREC_DATABASE_COL_SID] = {
         .name = "sid",
         .type = {
            .key = {
               .type = OVSDB_TYPE_UUID,
            },
            .value = OVSDB_BASE_VOID_INIT,
            .n_min = 0,
            .n_max = 1,
         },
         .is_mutable = true,
         .is_synthetic = false,
         .parse = serverrec_database_parse_sid,
         .unparse = serverrec_database_unparse_sid,
    },

};

struct ovsdb_idl_table_class serverrec_table_classes[SERVERREC_N_TABLES] = {
    {"Database", true, false,
     serverrec_database_columns, ARRAY_SIZE(serverrec_database_columns),
     sizeof(struct serverrec_database), serverrec_database_init__},
};

struct ovsdb_idl_class serverrec_idl_class = {
    "_Server", serverrec_table_classes, ARRAY_SIZE(serverrec_table_classes)
};

/* Return the schema version.  The caller must not free the returned value. */
const char *
serverrec_get_db_version(void)
{
    return "1.1.0";
}

