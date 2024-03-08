#include "board.h"
#include <QVector>
#include <QPoint>

// Constructeur de la classe Board
Board::Board(QObject *parent) : QObject(parent) {
    // Initialiser le plateau avec les positions initiales des pièces, si nécessaire
    resetBoard();
}

// Destructeur
Board::~Board() {
    // Nettoyage si nécessaire
}

// Réinitialise le plateau de jeu à son état initial
void Board::resetBoard() {
    // Exemple : Clear le vecteur des pièces et le remplir avec l'état initial du jeu
    pieces.clear();
    // Supposons que 'Piece' est une classe représentant une pièce sur le plateau
    // Vous devrez définir cette classe selon les besoins de votre jeu
    // Exemple d'ajout de pièces au plateau. Les positions doivent être adaptées selon les règles de votre jeu.
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 5; ++j) {
            if ((i < 3) || (i > 5) || (j < 2) || (j > 6)) {
                pieces.push_back(Piece(i, j, Piece::Color::Black));
            } else {
                pieces.push_back(Piece(i, j, Piece::Color::White));
            }
        }
    }
}

// Ajoute une pièce sur le plateau à une position spécifiée
void Board::addPiece(const QPoint& position, Piece::Color color) {
    pieces.push_back(Piece(position.x(), position.y(), color));
}

// Retire une pièce du plateau
void Board::removePiece(const QPoint& position) {
    // Trouver et supprimer la pièce à la position spécifiée
    auto it = std::find_if(pieces.begin(), pieces.end(), [&position](const Piece& piece) {
        return piece.getPosition() == position;
    });
    if (it != pieces.end()) {
        pieces.erase(it);
    }
}

// Vérifie si une position est occupée par une pièce
bool Board::isPositionOccupied(const QPoint& position) const {
    return std::any_of(pieces.begin(), pieces.end(), [&position](const Piece& piece) {
        return piece.getPosition() == position;
    });
}

// Obtient la liste des pièces sur le plateau
QVector<Piece> Board::getPieces() const {
    return pieces;
}
