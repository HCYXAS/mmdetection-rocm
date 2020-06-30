1)Requires:
addict
numpy
pyyaml
yapf
opencv-python
terminaltables
tesnorboard version>=1.14

pycocotools安装注意：
cd cocoapi-master/pycocotools/
python3 setup.py install



2)安装mmcv
git clone -b v0.6.2 https://github.com/open-mmlab/mmcv.git


3)mmdetection安装
CXX=hipcc CC=hipcc python3 setup.py install

