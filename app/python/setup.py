# -*- coding: utf-8 -*-

from setuptools import setup, find_packages

with open('README.md') as f:
    readme = f.read()

with open('LICENSE') as f:
    license = f.read()

setup(
    name='mySecurity',
    version='0.1.0',
    description='A Personal Computer Privacy Safer',
    long_description=readme,
    author='Felipe Tenório',
    author_email='FelipeFTN@protonmail.com',
    url='https://github.com/FelipeFTN/MySecurity',
    packages=find_packages(exclude=('tests', 'docs'))
)