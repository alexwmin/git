#include "graph.h"
static int diff_indent_heuristic; /* experimental */
		options->submodule_format = DIFF_SUBMODULE_LOG;
		options->submodule_format = DIFF_SUBMODULE_SHORT;
	else if (!strcmp(value, "diff"))
		options->submodule_format = DIFF_SUBMODULE_INLINE_DIFF;
int git_diff_heuristic_config(const char *var, const char *value, void *cb)
{
	if (!strcmp(var, "diff.indentheuristic")) {
		diff_indent_heuristic = git_config_bool(var, value);
		if (diff_indent_heuristic)
			diff_compaction_heuristic = 0;
	}
	if (!strcmp(var, "diff.compactionheuristic")) {
		diff_compaction_heuristic = git_config_bool(var, value);
		if (diff_compaction_heuristic)
			diff_indent_heuristic = 0;
	}
	return 0;
}

	if (git_diff_heuristic_config(var, value, cb) < 0)
		return -1;
	o->found_changes = 1;

		fprintf(o->file, "%s", ecbdata->header->buf);
		fprintf(o->file, "%s%s--- %s%s%s\n",
		fprintf(o->file, "%s%s+++ %s%s%s\n",
			putc('\n', o->file);
			emit_line(o, context, reset, line, len);
			fputs("~\n", o->file);
			emit_line(o, context, reset, line, len);
		emit_line(o, diff_get_color(ecbdata->color_diff, DIFF_CONTEXT),
		width = term_columns() - strlen(line_prefix);
	diff_set_mnemonic_prefix(o, "a/", "b/");
	if (DIFF_OPT_TST(o, REVERSE_DIFF)) {
		a_prefix = o->b_prefix;
		b_prefix = o->a_prefix;
	} else {
		a_prefix = o->a_prefix;
		b_prefix = o->b_prefix;
	}

	if (o->submodule_format == DIFF_SUBMODULE_LOG &&
	    (!one->mode || S_ISGITLINK(one->mode)) &&
	    (!two->mode || S_ISGITLINK(two->mode))) {
				&one->oid, &two->oid,
	} else if (o->submodule_format == DIFF_SUBMODULE_INLINE_DIFF &&
		   (!one->mode || S_ISGITLINK(one->mode)) &&
		   (!two->mode || S_ISGITLINK(two->mode))) {
		const char *del = diff_get_color_opt(o, DIFF_FILE_OLD);
		const char *add = diff_get_color_opt(o, DIFF_FILE_NEW);
		show_submodule_inline_diff(o->file, one->path ? one->path : two->path,
				line_prefix,
				&one->oid, &two->oid,
				two->dirty_submodule,
				meta, del, add, reset, o);
		return;
	if (hashcmp(sha1, ce->oid.hash) || !S_ISREG(ce->ce_mode))
	if (diff_indent_heuristic)
		DIFF_XDL_SET(options, INDENT_HEURISTIC);
	else if (diff_compaction_heuristic)
	else if (!strcmp(arg, "--indent-heuristic")) {
		DIFF_XDL_SET(options, INDENT_HEURISTIC);
		DIFF_XDL_CLR(options, COMPACTION_HEURISTIC);
	} else if (!strcmp(arg, "--no-indent-heuristic"))
		DIFF_XDL_CLR(options, INDENT_HEURISTIC);
	else if (!strcmp(arg, "--compaction-heuristic")) {
		DIFF_XDL_CLR(options, INDENT_HEURISTIC);
	} else if (!strcmp(arg, "--no-compaction-heuristic"))
		options->submodule_format = DIFF_SUBMODULE_LOG;
	else if ((argcount = parse_long_opt("line-prefix", av, &optarg))) {
		options->line_prefix = optarg;
		options->line_prefix_length = strlen(options->line_prefix);
		graph_setup_line_prefix(options);
		return argcount;
	}