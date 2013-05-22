# -*- coding: utf-8 -*-

import pygame
from pygame.locals import QUIT 
import scenes
from scenes import SceneManager

class Display():
    def __init__(self):
        self.screen = pygame.display.set_mode((620,480))

    def handleEvents(self):
		for e in pygame.event.get() :
			if e.type == QUIT:
				SceneManager.exit();

class Main(object):
    def __init__(self):
        pygame.init()
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

