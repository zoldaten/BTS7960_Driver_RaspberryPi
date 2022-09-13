from xml.etree.ElementInclude import include
from setuptools import setup, find_packages

setup(
    name='bts7960',
    version='0.0.1',
    description="Gpio program to controll the BTS7960 of a robotics project",
    author="Louis Castro",
    author_email="castrolwilliam@gmail.com",
    packages=find_packages(include=['lib','lib.*']),
    install_requires=[
        'RPi.GPIO'
    ]
);
