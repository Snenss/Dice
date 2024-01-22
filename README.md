# Projektbeschreibung
Dieses Projekt steuert einen 7-LED Würfel. Per Tastendruck kann eine Zufallszahl erzeugt werden.
Das Gerät kann in einen Ruhemodus gehen, welcher auch am Gerät deaktivirbar ist

# Hardware
Der 7-LED Würfel wurde auf einem Breadboard per RPI Pico W realisiert
Detailliierte Anleitungen finden sich in der Benutzerdokumentation / Entwicklerdokumentation

# Software
Programm geschrieben in c.
Programm unterteil in:
-dice.c
-dice_hardware.c
-dice_animation.c

# Branch
Zu Testzwecken wurde ein Branch hinzugefügt, welcher ein Alternatives Anzeigeformat der LEDs implementiert

# Inbetriebnahme
Für die schnelle Inbetriebnahme befindet sich das fertig kompilierte Programm: „dice.uf2“ innerhalb
dieses Repos unter /build

# Bitte beachten
Ausführliche Beschreibungen sind in den beiden PDF Dateien zu finden
