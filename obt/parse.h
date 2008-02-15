/* -*- indent-tabs-mode: nil; tab-width: 4; c-basic-offset: 4; -*-

   obt/parse.h for the Openbox window manager
   Copyright (c) 2003-2007   Dana Jansens

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   See the COPYING file for a copy of the GNU General Public License.
*/

#ifndef __obt_parse_h
#define __obt_parse_h

#include <libxml/parser.h>
#include <glib.h>

G_BEGIN_DECLS

typedef struct _ObtParseInst ObtParseInst;

typedef void (*ObtParseCallback)(xmlNodePtr node, gpointer data);

ObtParseInst* obt_parse_instance_new(void);
void obt_parse_instance_ref(ObtParseInst *inst);
void obt_parse_instance_unref(ObtParseInst *inst);

gboolean obt_parse_load_file(ObtParseInst *inst,
                             const gchar *path,
                             const gchar *root_node);
gboolean obt_parse_load_config_file(ObtParseInst *inst,
                                    const gchar *domain,
                                    const gchar *filename,
                                    const gchar *root_node);
gboolean obt_parse_load_data_file(ObtParseInst *inst,
                                  const gchar *domain,
                                  const gchar *filename,
                                  const gchar *root_node);
gboolean obt_parse_load_theme_file(ObtParseInst *inst,
                                   const gchar *theme,
                                   const gchar *domain,
                                   const gchar *filename,
                                   const gchar *root_node);
gboolean obt_parse_load_mem(ObtParseInst *inst,
                            gpointer data, guint len, const gchar *root_node);

xmlDocPtr obt_parse_doc(ObtParseInst *inst);
xmlNodePtr obt_parse_root(ObtParseInst *inst);

void obt_parse_close(ObtParseInst *inst);

void obt_parse_register(ObtParseInst *inst, const gchar *tag,
                        ObtParseCallback func, gpointer data);
void obt_parse_tree(ObtParseInst *i, xmlNodePtr node);
void obt_parse_tree_from_root(ObtParseInst *i);


/* helpers */

xmlNodePtr obt_parse_find_node(xmlNodePtr node, const gchar *name);

gboolean obt_parse_node_contains (xmlNodePtr node, const gchar *val);
gchar   *obt_parse_node_string   (xmlNodePtr node);
gint     obt_parse_node_int      (xmlNodePtr node);
gboolean obt_parse_node_bool     (xmlNodePtr node);

gboolean obt_parse_attr_contains (xmlNodePtr node, const gchar *name,
                                  const gchar *val);
gboolean obt_parse_attr_string   (xmlNodePtr node, const gchar *name,
                                  gchar **value);
gboolean obt_parse_attr_int      (xmlNodePtr node, const gchar *name,
                                  gint *value);
gboolean obt_parse_attr_bool     (xmlNodePtr node, const gchar *name,
                                  gboolean *value);

G_END_DECLS

#endif
