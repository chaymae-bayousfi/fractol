# 🌌 Fractol

Bienvenue sur **Fractol**, un projet C permettant de générer et explorer des fractales magnifiques telles que Mandelbrot et Julia en utilisant la librairie graphique MiniLibX !  
Plongez dans l'univers fascinant des mathématiques visuelles et amusez-vous à manipuler les paramètres pour créer vos propres œuvres d’art fractales. ✨

---

## 🚀 Aperçu du projet

Fractol est une application graphique interactive permettant de visualiser différents types de fractales :

- **Mandelbrot** 🟣
- **Julia** 🟢

L’utilisateur peut zoomer/dézoomer, fermer la fenêtre, et manipuler les paramètres pour explorer l’infini des fractales.

---

## 🖥️ Capture d’écran

![Aperçu Fractol](https://user-images.githubusercontent.com/your-github-user/screenshots/fractol-demo.png)

---

## ⚙️ Installation

### 1. Prérequis

- **macOS** (MiniLibX requiert macOS pour fonctionner avec les frameworks OpenGL & AppKit)
- `make`
- `cc` (compilateur C)
- MiniLibX installée ([lien officiel](https://github.com/42Paris/minilibx-linux) pour Linux ou incluse pour macOS)

### 2. Compilation

Clonez le projet et compilez-le :

```bash
git clone https://github.com/chaymae-bayousfi/fractol.git
cd fractol/fractol
make
```

---

## 🕹️ Utilisation

### 1. Mandelbrot

```bash
./fractol mandelbrot
```
Affiche la fractale de Mandelbrot.

### 2. Julia

```bash
./fractol julia <re> <im>
```
Affiche la fractale de Julia avec les paramètres :
- `<re>` : partie réelle du nombre complexe (dans l’intervalle [-2, 2])
- `<im>` : partie imaginaire (dans l’intervalle [-2, 2])

**Exemple :**
```bash
./fractol julia 0.285 0.01
```

---

## 🖱️ Interactions

| Touche / Souris          | Action                                             |
|--------------------------|----------------------------------------------------|
| `Molette haut` 🖱️⬆️      | Zoom avant sur la fractale                         |
| `Molette bas` 🖱️⬇️       | Zoom arrière sur la fractale                       |
| `ESC` ⎋                  | Fermer la fenêtre et quitter le programme          |
| `Fermer la fenêtre` ❌   | Quitter proprement                                 |

---

## 📁 Structure du projet

```
fractol/
│
├── fractol.c        # Fonction principale et rendu graphique
├── handler_fun.c    # Gestion des événements clavier/souris & validation
├── libft.c          # Fonctions utilitaires (strcmp, atof, etc.)
├── math.c           # Calculs mathématiques et gestion des couleurs
├── fractol.h        # Déclarations des structures et prototypes
├── Makefile         # Compilation rapide du projet
```

---

## 🎯 Objectifs pédagogiques

- Approfondir les mathématiques complexes et les fractales
- Approche algorithmique du dessin
- Manipulation de la MiniLibX (MLX) pour le rendu graphique
- Gestion d’événements clavier et souris

---

## 🛠️ Personnalisation

Vous pouvez modifier les couleurs, le nombre d’itérations, ou ajouter d’autres fractales dans le code source (`fractol.c`, `math.c`).

---

## 📝 Aide & erreurs

Si vous lancez le programme avec des arguments invalides, un message d’aide s’affichera :

```bash
> ./fractol mandelbrot
> ./fractol julia < re > < im > ( re/im in [-2,2] )
```

---

## 👩‍💻 Auteur

- [chaymae-bayousfi](https://github.com/chaymae-bayousfi)

---

## ⭐️ N’hésitez pas à laisser un ⭐️ si ce projet vous plaît !
