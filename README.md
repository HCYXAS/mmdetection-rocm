1)Requires:
addict
numpy
pyyaml
yapf
opencv-python
terminaltables
tesnorboard version>=1.14

pycocotools安装注意：
a.安装open-mmlab支持版本：https://github.com/open-mmlab/cocoapi
b.直接安装目录下的文件
cd pkg
unzip cocoapi-master.zip
python3 setup.py install



2)安装mmcv
git clone -b v0.6.2 https://github.com/open-mmlab/mmcv.git
或直接在./pkg下获取

3)mmdetection安装
CXX=hipcc CC=hipcc python3 setup.py install

