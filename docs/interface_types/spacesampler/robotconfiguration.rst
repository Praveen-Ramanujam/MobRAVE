.. _spacesampler-robotconfiguration:

RobotConfiguration - basesamplers
---------------------------------

:Type: :ref:`interface-spacesampler`

:Plugin: :ref:`plugin-basesamplers`

:Interface Author: Rosen Diankov

Samples the robot active configuration space, treats revolute and circular joints appropriately. When creating pass the following parameters::

  RobotConfiguration [robot name] [sampler name]

The sampler needs to return values in the range [0,1]. Default sampler is 'mt19937'.



RobotConfiguration Commands
===========================


.. _spacesampler-robotconfiguration-help:


help
~~~~

display help commands.

~~~~

