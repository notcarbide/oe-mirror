/* SPDX-License-Identifier: GPL-2.0+ */
/* Copyright (c) 2021 Hisilicon Limited. */

#ifndef __HNS3_DEBUGFS_H
#define __HNS3_DEBUGFS_H

#include "hnae3.h"

#define HNS3_DBG_READ_LEN	65536
#define HNS3_DBG_WRITE_LEN	1024

enum hns3_dbg_dentry_type {
	HNS3_DBG_DENTRY_TM,
	HNS3_DBG_DENTRY_COMMON,
};

struct hns3_dbg_dentry_info {
	const char *name;
	struct dentry *dentry;
};

struct hns3_dbg_cmd_info {
	const char *name;
	enum hnae3_dbg_cmd cmd;
	enum hns3_dbg_dentry_type dentry;
	u32 buf_len;
	char *buf;
	int (*init)(struct hnae3_handle *handle, unsigned int cmd);
};

#endif