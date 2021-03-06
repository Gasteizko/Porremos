<?php

require_once('GrupoDAO.inc');

class Grupo {
  private $id;
  private $nombre;
  private $descripcion;

  private $gdao;

  public function __construct(GrupoDAO $gdao = NULL) {
    if($gdao)
      $this->gdao = $gdao;
    else
      $this->gdao = new GrupoDAO();
  }

  public function getId() {
    return $this->id;
  }

  public function getNombre() {
    return htmlspecialchars($this->nombre);
  }

  public function getDescripcion() {
    return htmlspecialchars($this->descripcion);
  }

  public function setId($id) {
    $this->id = $id;
  }

  public function setNombre($nombre) {
    $this->nombre = $nombre;
  }

  public function setDescripcion($descripcion) {
    $this->descripcion = $descripcion;
  }

///////////////////////////
/// Metodos funcionales ///
///////////////////////////

  public function save() {
     $this->gdao->save($this);
  }

  public function getClasificacion() {
     return $this->gdao->getClasificacion($this->getId());
  }

  public function addUser($email) {
     return $this->gdao->addUser($this->getId(), $email);
  }

  public function removeUser($userid) {
     return $this->gdao->removeUser($this->getId(), $userid);
  }
}

?>
