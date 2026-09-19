# Visual_Computing_1

Gesichts- und Augenerkennung in C++ mit OpenCV (Haar-Cascade-Klassifikatoren), im Rahmen des Moduls "Visual Computing 1" an der ZHAW.

## Voraussetzungen

- Visual Studio mit der Workload "Desktopentwicklung mit C++" (inkl. CMake-Tools-Unterstützung)
- vcpkg, siehe Abschnitt "vcpkg einrichten" unten
- Eine Webcam (das Programm öffnet standardmässig Kamera-Index 0)
- Internetzugang beim allerersten Build: vcpkg lädt OpenCV und dessen Abhängigkeiten (u. a. protobuf, abseil, libjpeg-turbo) herunter und kompiliert sie lokal. Das kann beim ersten Mal 20–60+ Minuten dauern, je nach Rechenleistung. Bei jedem weiteren Build entfällt das.

## vcpkg einrichten

Dieses Projekt nutzt vcpkg im Manifest-Modus (`vcpkg.json`), um OpenCV beim Konfigurieren automatisch zu installieren. Damit das funktioniert, muss auf dem Rechner eine vcpkg-Installation vorhanden sein, und die Umgebungsvariable `VCPKG_ROOT` muss darauf zeigen – darüber findet `CMakePresets.json` den Toolchain-Pfad. Zwei Wege, das einzurichten:

**Option A – über den Visual Studio Installer (am einfachsten):** Im Visual Studio Installer unter "Einzelne Komponenten" den Eintrag "vcpkg package manager" auswählen und installieren. Visual Studio setzt `VCPKG_ROOT` dabei automatisch.

**Option B – manuell:**
```
git clone https://github.com/microsoft/vcpkg
cd vcpkg
.\bootstrap-vcpkg.bat
```
Danach die Umgebungsvariable `VCPKG_ROOT` auf diesen Ordner setzen, z. B. dauerhaft per PowerShell:
```
setx VCPKG_ROOT "C:\Pfad\zu\vcpkg"
```
Anschliessend Terminal bzw. Visual Studio neu starten, damit die Änderung greift.

Ob `VCPKG_ROOT` korrekt gesetzt ist, lässt sich in einer PowerShell mit `echo $env:VCPKG_ROOT` prüfen – die Ausgabe sollte auf den vcpkg-Ordner zeigen.

## Setup

1. Repository klonen.
2. Ordner in Visual Studio öffnen ("Ordner öffnen") – CMake wird automatisch erkannt.
3. Als Konfiguration `x64-debug` (oder `x64-release`) wählen.
4. Beim ersten Konfigurieren installiert vcpkg automatisch OpenCV (gesteuert über `vcpkg.json` und den Toolchain-Eintrag in `CMakePresets.json`) – einfach abwarten, bis der Build-Vorgang durchläuft.
5. Projekt erstellen (Strg+Umschalt+B bzw. "Alles erstellen").

## Ausführen

- Direkt über den grünen "Start"-Pfeil in Visual Studio, oder die gebaute `.exe` unter `out/build/<preset>/Visual_Computing_1.exe`.
- Das Programm öffnet die Standard-Webcam und zeichnet erkannte Gesichter (blauer Kreis) sowie Augen ein.
- Beenden mit `q`, `Q` oder `Esc`, während das Kamerafenster im Fokus ist.

## Ressourcen

Die benötigten Haar-Cascade-XML-Dateien liegen bereits im Repository unter `resources/haarcascades/` und werden beim Klonen automatisch mitgeliefert – kein manueller Download nötig. Die Pfade dazu sind im Code über das CMake-Macro `PROJECT_SOURCE_DIR` fest verankert, damit sie unabhängig vom aktuellen Arbeitsverzeichnis zuverlässig gefunden werden.