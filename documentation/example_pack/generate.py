import zipfile
import os
import casadi
release = casadi.__version__

import zlib
compression = zipfile.ZIP_DEFLATED
zf = zipfile.ZipFile('example_pack.zip', mode='w')


if "+" in release:
  releasedocurl = "http://casadi.sourceforge.net/api/html/annotated.html"
else:
  releasedocurl = "http://casadi.sourceforge.net/v%s/api/html/annotated.html" % release

zf.writestr('README.txt',"""

This is a collection of python exmaples for CasADi %s.
Consult the documentation online at %s.

To run an example vdp_single_shooting.py, you have several options:

a) fire up a terminal, navigate to this directory, and type "python vdp_single_shooting.py"
b) fire up a terminal, navigate to this directory, and type "ipython" and then "run vdp_single_shooting.py"
c) start spyder, open vdp_single_shooting.py and press "run".

    
""" % (release,releasedocurl))

base = "../../examples/python"
for root, dirs, files in os.walk(base): # Walk directory tree
  for f in files:
    if f.endswith(".py"):
       zf.write(os.path.join(root,f),f,compress_type=compression)

base = "../../documents"
for root, dirs, files in os.walk(base): # Walk directory tree
  for f in files:
    if f.endswith(".pdf"):
       zf.write(os.path.join(root,f),f,compress_type=compression)

zf.write("../cheatsheet/python.pdf","cheatsheet.pdf",compress_type=compression)
zf.write("../users_guide/casadi-users_guide.pdf","user_guide.pdf",compress_type=compression)

zf.close()
