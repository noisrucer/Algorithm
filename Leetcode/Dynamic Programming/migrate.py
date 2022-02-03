import os
import sys
import re

fname_list = os.listdir()

# CONFIGURATIONS - Modify Below
######################################################################################
EXTENSION = 'cpp' # Original extension of your files
DEST_LOCATION = '~/Desktop/jasonlee-github-blog/JasonLee-cp.github.io/_posts/Algorithm/DP/'
TITLE_PREFIX = '[DP] ' # This is for "[category] title..." format. Replace with '' if you don't need it.
POST_CATEGORY = 'dp' # Jekyll post category
POSTING_DATE = '2022-02-02-' # Posting date
TAGS = ['algorithm', 'dp'] # List of tags for your post
REMOVE_LIST = ['#', ' '] # Remove from ".md" file name. Not the post title. The title will be the same as original file name with extension removed.
#######################################################################################

for fname in fname_list:
    if os.path.isdir(fname): # skip if it's a dir
        break
    if not fname.endswith(f'.{EXTENSION}'): # only covert files with given extension
        break

    with open(fname, 'r') as file:
        contents = f'---\nlayout: single\ntitle: "{TITLE_PREFIX}{fname[:-1*len(EXTENSION)]}"\ncategories: ["{POST_CATEGORY}"]\ntag: [{", ".join(TAGS)}]\n---\n```{EXTENSION}\n'
        while True:
            line = file.readline()
            if not line:
                break
            contents += line

    contents += '\n```'

    # convert .cpp to .md / remove whitespaces
    fname = re.sub(f'.{EXTENSION}', '.md', fname.strip())

    # Remove from '.md' file name, NOT from the post title
    for remove in REMOVE_LIST:
        remove = '\s' if remove == ' ' else remove
        fname = re.sub(remove,'', fname)

    fname = POSTING_DATE + fname.strip()

    # write file
    f = open(f'./mdfiles/{fname}','w')
    f.write(contents)
    f.close()

os.system(f"cp ./mdfiles/* {DEST_LOCATION}")

print("Migration Complete")