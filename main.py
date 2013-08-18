# -*- coding: utf-8 -*-

import scenes
from scenes import SceneManager
from adaptors import Display

class Main(object):
    def __init__(self):
        self.display = Display()
        SceneManager.setDisplay(self.display)
        firstScene = scenes.SceneTeste()
        SceneManager.setCurrentScene(firstScene)

    def __del__(self):
        pass

if __name__ == "__main__":
    game = Main()
    SceneManager.run()
    del game

