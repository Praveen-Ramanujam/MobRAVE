.. _module-grasper:

Grasper - grasper
-----------------

:Type: :ref:`interface-module`

:Plugin: :ref:`plugin-grasper`

:Interface Author: Rosen Diankov

Used to simulate a hand grasping an object by closing its fingers until collision with all links. 


Grasper Commands
================


.. _module-grasper-computedistancemap:


ComputeDistanceMap
~~~~~~~~~~~~~~~~~~

Computes a distance map around a particular point in space

~~~~


.. _module-grasper-convexhull:


ConvexHull
~~~~~~~~~~

Given a point cloud, returns information about its convex hull like normal planes, vertex indices, and triangle indices. Computed planes point outside the mesh, face indices are not ordered, triangles point outside the mesh (counter-clockwise)

~~~~


.. _module-grasper-getstablecontacts:


GetStableContacts
~~~~~~~~~~~~~~~~~

Returns the stable contacts as defined by the closing direction

~~~~


.. _module-grasper-grasp:


Grasp
~~~~~

Performs a grasp and returns contact points

~~~~


.. _module-grasper-graspthreaded:


GraspThreaded
~~~~~~~~~~~~~

Parllelizes the computation of the grasp planning and force closure. Number of threads can be specified with 'numthreads'.

~~~~


.. _module-grasper-help:


help
~~~~

display help commands.

~~~~

