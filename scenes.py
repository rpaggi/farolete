# -*- coding: utf-8 -*-

class SceneManager(object):
    # TODO
    # scene stack
    # start, pause, stop scene
    scene = None
    screen = None

    @staticmethod
    def setDisplay(display):
        """Set Screen object to draw the game"""
        SceneManager.display = display
        SceneManager.screen = display.screen

    @staticmethod
    def setCurrentScene(scene):
        """Set the current running Scene"""
        SceneManager.scene = scene

    @staticmethod
    def getCurrentScene():
        """Get the current running Scene"""
        return SceneManager.scene

    @staticmethod
    def run():
        """Run the game. It calls the main method of a scene always
        whe it changes."""
        while SceneManager.scene != None:
            SceneManager.scene.main()

    @staticmethod
    def isScene(scene):
        """Verify if the current scene still the same"""
        return SceneManager.scene == scene

    @staticmethod
    def exit():
        """Finish game execution"""
        SceneManager.scene = None

class Scene(object):
    context = None

    def main(self):
        self.start()
        while SceneManager.isScene(self):
            SceneManager.display.handleEvents()
            self.update()

        self.finish()

    def start(self):
        """Overload this method to initialize and setup  objects used
        in scene"""
        pass

    def update(self):
        self.draw()
        self.render()
        self.logic()

    def finish(self):
        """Overload this method to release correctly(if necessary)
        objects and prepare context to next scene"""
        pass

    def draw(self):
        """Overload this method to draw objects used
        in scene onto screen"""
        pass

    def render(self):
        """Overload this method to parse object's states of
        scene and redefine it's visual presentation onto screen"""
        pass

    def logic(self):
        """Overload this method to process the game logic of
        the scene"""
        pass


class SceneTeste(Scene):
    def start(self):
        self.timer = 24
        print "Valendo!"

    def draw(self):
        print "Desenhando"

    def render(self):
        print "Renderizando"

    def logic(self):
        if not self.timer:
            SceneManager.exit()
        print "Processando"
        self.timer -= 1

    def finish(self):
        print "Acabou!"
