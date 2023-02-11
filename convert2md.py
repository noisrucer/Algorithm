import os
import os.path as osp

date = "2022-05-20"
source_dir = "/Users/jasonlee/Desktop/Algorithm-Master/Tree"
target_dir = "/Users/jasonlee/Desktop/noisrucervlog.github.io/_posts/algorithm/tree"

q_type = "tree"
extension_type = "cpp"
prefix = "#" # Starting with # are Leetcode problems.

new_post_template = """---
layout: post
title: "[Leetcode] __TITLE__"
subtitle: ""
categories: algorithm
tags: __TAG__
comments:
---

## Link: [__QUESTION_NAME__](https://leetcode.com/problems/__LINK__/)

```__EXTENSION_TYPE__
__CONTENT__
```
"""

for fname in os.listdir(source_dir):
    if not fname.endswith(extension_type):
        continue
    if not fname.startswith(prefix):
        continue

    fpath = osp.join(source_dir, fname)

    first_alpha_idx = None
    for idx in range(len(fname)):
        if fname[idx] == ' ':
            first_alpha_idx = idx + 1
            break

    fname_without_extension = fname[1: -1 * (len(extension_type) + 1)]
    original_question_name = fname[first_alpha_idx: -1 * (len(extension_type) + 1)]
    original_question_name = '-'.join(original_question_name.lower().split(' '))\
                                                                .replace('\'','')\
                                                                .replace('\"','')
    with open(fpath, 'r') as f:
        content = f.read()
        new_post = new_post_template\
                    .replace('__TITLE__', fname_without_extension)\
                    .replace('__TAG__', q_type)\
                    .replace('__EXTENSION_TYPE__', extension_type)\
                    .replace('__CONTENT__', content)\
                    .replace('__LINK__', original_question_name)\
                    .replace('__QUESTION_NAME__', fname_without_extension)

    new_fname = f"{date}-{fname_without_extension}.md"
    new_fpath = osp.join(target_dir, new_fname)

    with open(new_fpath, 'w') as f:
        f.write(new_post)


