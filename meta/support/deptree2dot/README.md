deptree2dot - Graph the UQIS Dependency Tree
==============================================

This utility can be used to graph the UQIS dependency tree. It
requires perl5.x and converts the tree to a .dot file which can be
processed by graphviz.

Example usage:

$ chmod +x deptree2dot
$deptree2dot > deptree.dot
$deptree2dot | dot -Tpng -o deptree.png
