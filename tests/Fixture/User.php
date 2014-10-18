<?php

namespace Bee\Test\Fixture;

class User
{
    /**
     * @var string
     */
    private $username;
    /**
     * @var bool
     */
    private $banned;
    /**
     * @var \DateTime
     */
    private $createdAt;

    public function __construct($username, $banned = false)
    {
        $this->createdAt = new \DateTime();
        $this->username = $username;
        $this->banned = $banned;
    }

    public function getUsername()
    {
        return $this->username;
    }

    public function setUsername($username)
    {
        $this->username = $username;
    }

    public function isBanned()
    {
        return $this->banned;
    }

    public function setBanned($banned)
    {
        $this->banned = $banned;
    }

    public function getCreatedAt()
    {
        return $this->createdAt;
    }

    public function hasVirtual()
    {
        return true;
    }
}
