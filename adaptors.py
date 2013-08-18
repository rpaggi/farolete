# -*- coding: utf-8 -*-
from pytmx import tmxloader
import pygame
from pygame.locals import *

pygame.init()

class Display(object):
    def __init__(self):
        self.screen = pygame.display.set_mode((620,480))

    def handleEvents(self, SceneManager):
        for e in pygame.event.get(QUIT):
            SceneManager.exit()

    def update(self, areas=()):
        pygame.display.update(areas)

class LevelLoader(object):
    def __init__(self):
        pass

    @staticmethod
    def load(filename):
        return tmxloader.load_pygame(filename, pixelalpha=True)
