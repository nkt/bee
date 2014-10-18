namespace Bee;

/**
 * @author Nikita Gusakov <dev@nkt.me>
 */
class Serializer
{
    public function serialize(obj, array keys) -> array
    {
        var data = [], key, value, property;

        if typeof obj == "array" {
            for value in obj {
                let data[] = this->serialize(value, keys);
            }
        } else {
            for key, value in keys {
                if typeof key == "string" {
                    let property = this->getProperty(obj, key);
                    if typeof property == "null" {
                        let data[key] = null;
                    } else {
                        let data[key] = this->serialize(property, value);
                    }
                } else {
                    let property = this->getProperty(obj, value);
                    if property instanceof \DateTime {
                        let property = property->format(\DateTime::ISO8601);
                    }
                    let data[value] = property;
                }
            }
        }

        return data;
    }

    public function getProperty(object obj, string property)
    {
        string method;

        let method = "get" . property;
        if method_exists(obj, method) {
            return obj->{method}();
        } else {
            let method = "is" . property;
            if (method_exists(obj, method)) {
                return obj->{method}();
            } else {
                let method = "has" . property;
                if (method_exists(obj, method)) {
                    return obj->{method}();
                }
            }
        }
        throw new \RuntimeException(get_class(obj) . " has no accessor for " . property);
    }
}
