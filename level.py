# -*- coding: utf-8 -*-
from adaptors import LevelLoader
from adaptors import Display

class Map(object):
    def __init__(self, fileName):
        self.data = LevelLoader.load(fileName)

    def render(self, screen):
        self.tileWidth = self.data.tilewidth
        self.tileHeigth = self.data.tileheight

        for layer in xrange(0, len(self.data.tilelayers)):
            for y in xrange(0, self.data.height):
                for x in xrange(0, self.data.width):
                    tile = self.data.getTileImage(x, y, layer)
                    if tile: screen.blit(tile, (x*self.tileWidth, y*self.tileHeigth))

