.. _viewer-qtcoin:

QtCoin - qtcoinrave
-------------------

:Type: :ref:`interface-viewer`

:Plugin: :ref:`plugin-qtcoinrave`

:Interface Author: Rosen Diankov

Provides a GUI using the Qt4, Coin3D, and SoQt libraries. Depending on the version, Coin3D and SoQt might be licensed under GPL.

If the current directory contains a filename **environment.iv** when the qtcoin viewer is loaded, then this file will define the scene file all other elements are loaded under. This allows users to define their own lighting model. For example, the following **environment.iv** file will force every object to be draw as wirefire:

.. code-block:: c

  #Inventor V2.1 ascii

  Separator {
  DrawStyle { style LINES  lineWidth 2 }
  }




QtCoin Commands
===============


.. _viewer-qtcoin-help:


help
~~~~

display help commands.

~~~~


.. _viewer-qtcoin-setfiguresincamera:


SetFiguresInCamera
~~~~~~~~~~~~~~~~~~

Accepts 0/1 value that decides whether to render the figure plots in the camera image through GetCameraImage

~~~~

