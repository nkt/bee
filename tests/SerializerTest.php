<?php

namespace Bee\Test;

use Bee\Serializer;
use Bee\Test\Fixture\User;

class SerializerTest extends \PHPUnit_Framework_TestCase
{
    /**
     * @dataProvider getSerializeData
     */
    public function testSerialize($object, $keys, $result)
    {
        $serializer = new Serializer();

        $this->assertEquals($result, $serializer->serialize($object, $keys));
    }

    public function getSerializeData()
    {
        $user = new User('nkt');

        return array(
            array($user, array(), array()),
            array($user, array('username'), array('username' => 'nkt')),
            array(array($user), array('username'), array(array('username' => 'nkt'))),
            // @TODO: implement this
            // array(new \ArrayObject(array($user)), array('username'), array(array('username' => 'nkt'))),
        );
    }

    /**
     * @dataProvider getPropertyData
     */
    public function testGetProperty($object, $property, $value)
    {
        $serializer = new Serializer();

        $this->assertEquals($value, $serializer->getProperty($object, $property));
    }

    public function getPropertyData()
    {
        $user = new User('nkt');

        return array(
            array($user, 'username', 'nkt'),
            array($user, 'banned', false),
            array($user, 'virtual', true),
            array($user, 'createdAt', $user->getCreatedAt()),
        );
    }
}
